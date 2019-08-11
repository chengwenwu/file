#include "Smtp.h"
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

char* CSmtp::base64Encode(char const* origSigned, unsigned origLength)
{
	unsigned char const* orig = (unsigned char const*)origSigned; // in case any input bytes have the MSB set
	if (orig == NULL) return NULL;

	unsigned const numOrig24BitValues = origLength / 3;
	bool havePadding = origLength > numOrig24BitValues * 3;
	bool havePadding2 = origLength == numOrig24BitValues * 3 + 2;
	unsigned const numResultBytes = 4 * (numOrig24BitValues + havePadding);
	char* result = new char[numResultBytes + 3]; // allow for trailing '/0'

	unsigned i;
	for (i = 0; i < numOrig24BitValues; ++i)
	{
		result[4 * i + 0] = base64Char[(orig[3 * i] >> 2) & 0x3F];
		result[4 * i + 1] = base64Char[(((orig[3 * i] & 0x3) << 4) | (orig[3 * i + 1] >> 4)) & 0x3F];
		result[4 * i + 2] = base64Char[((orig[3 * i + 1] << 2) | (orig[3 * i + 2] >> 6)) & 0x3F];
		result[4 * i + 3] = base64Char[orig[3 * i + 2] & 0x3F];
	}

	if (havePadding)
	{
		result[4 * i + 0] = base64Char[(orig[3 * i] >> 2) & 0x3F];
		if (havePadding2)
		{
			result[4 * i + 1] = base64Char[(((orig[3 * i] & 0x3) << 4) | (orig[3 * i + 1] >> 4)) & 0x3F];
			result[4 * i + 2] = base64Char[(orig[3 * i + 1] << 2) & 0x3F];
		}
		else
		{
			result[4 * i + 1] = base64Char[((orig[3 * i] & 0x3) << 4) & 0x3F];
			result[4 * i + 2] = '=';
		}
		result[4 * i + 3] = '=';
	}

	result[numResultBytes] = '\0';
	return result;
}

CSmtp::CSmtp(void)
{
	this->content = "";
	this->port = 25;
	this->user = "";
	this->pass = "";
	this->targetAddr = "";
	this->title = "";
	this->domain = "";

#ifdef _MSC_VER
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 1);
	err = WSAStartup(wVersionRequested, &wsaData);
#endif
	this->sockClient = 0;
}

CSmtp::~CSmtp(void)
{
#ifdef _MSC_VER
	closesocket(sockClient);
	WSACleanup();
#else
	close(sockClient);
#endif
}

CSmtp::CSmtp(
	int port,
	string srvDomain,
	string userName,
	string password,
	string targetEmail,
	string emailTitle,
	string content
)
{
	this->content = content;
	this->port = port;
	this->user = userName;
	this->pass = password;
	this->targetAddr = targetEmail;
	this->title = emailTitle;
	this->domain = srvDomain;

#ifdef _MSC_VER
	WORD wVersionRequested;
	WSADATA wsaData;
	int err;
	wVersionRequested = MAKEWORD(2, 1);
	err = WSAStartup(wVersionRequested, &wsaData);
#endif
	this->sockClient = 0;
}

bool CSmtp::CreateConn()
{
	int skClientTemp = (int)socket(AF_INET, SOCK_STREAM, 0);
	sockaddr_in saddr;
	hostent* pHostent;
	pHostent = gethostbyname(domain.c_str());

	saddr.sin_addr.s_addr = *((unsigned long*)pHostent->h_addr_list[0]);
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(port);
	int err = connect(skClientTemp, (sockaddr*)&saddr, sizeof(saddr));
	if (err != 0)
		return false;
	this->sockClient = (int)skClientTemp;
	if (false == Recv())
		return false;
	return true;
}

bool CSmtp::Send(string& strMessage)
{
	int err = (int)send(sockClient, strMessage.c_str(), (int)strMessage.length(), 0);
	if (err < 0)
	{
		return false;
	}
	cout << strMessage.c_str() << endl;
	return true;
}

bool CSmtp::Recv()
{
	memset(buff, 0, sizeof(char)* (MAX_EMAIL_MESSAGE_LEN + 1));
	int err = recv(sockClient, buff, MAX_EMAIL_MESSAGE_LEN, 0);
	if (err < 0)
	{
		return false;
	}
	buff[err] = '\0';
	cout << buff << endl;
	return true;
}

int CSmtp::Login()
{
	string sendBuff;
	sendBuff = "EHLO ";
	sendBuff += user;
	sendBuff += "\r\n";

	if (false == Send(sendBuff) || false == Recv())
		return 1;

	sendBuff.empty();
	sendBuff = "AUTH LOGIN\r\n";
	if (false == Send(sendBuff) || false == Recv())
		return 1;

	sendBuff.empty();
	int pos = (int)user.find('@', 0);
	sendBuff = user.substr(0, pos);

	char *ecode;

	ecode = base64Encode(sendBuff.c_str(), (unsigned int)strlen(sendBuff.c_str()));
	sendBuff.empty();
	sendBuff = ecode;
	sendBuff += "\r\n";
	delete[]ecode;

	if (false == Send(sendBuff) || false == Recv())
		return 1;

	sendBuff.empty();
	ecode = base64Encode(pass.c_str(), (unsigned int)strlen(pass.c_str()));
	sendBuff = ecode;
	sendBuff += "\r\n";
	delete[]ecode;

	if (false == Send(sendBuff) || false == Recv())
		return 1;

	if (NULL != strstr(buff, "550"))
		return 2;

	if (NULL != strstr(buff, "535"))
		return 3;
	return 0;
}

bool CSmtp::SendEmailHead()
{
	string sendBuff;
	sendBuff = "MAIL FROM: <" + user + ">\r\n";
	if (false == Send(sendBuff) || false == Recv())
		return false;

	sendBuff.empty();
	sendBuff = "RCPT TO: <" + targetAddr + ">\r\n";
	if (false == Send(sendBuff) || false == Recv())
		return false;

	sendBuff.empty();
	sendBuff = "DATA\r\n";
	if (false == Send(sendBuff) || false == Recv())
		return false;

	sendBuff.empty();
	FormatEmailHead(sendBuff);
	if (false == Send(sendBuff))
		return false;

	return true;
}

void CSmtp::FormatEmailHead(string& strEmail)
{
	strEmail = "From: ";
	strEmail += user;
	strEmail += "\r\n";

	strEmail += "To: ";
	strEmail += targetAddr;
	strEmail += "\r\n";

	strEmail += "Subject: ";
	strEmail += title;
	strEmail += "\r\n";

	strEmail += "MIME-Version: 1.0";
	strEmail += "\r\n";

	strEmail += "Content-Type: multipart/mixed;boundary=qwertyuiop";
	strEmail += "\r\n";
	strEmail += "\r\n";
}

bool CSmtp::SendTextBody()
{
	string sendBuff;
	sendBuff = "--qwertyuiop\r\n";
	sendBuff += "Content-Type: text/plain;";
	sendBuff += "charset=\"gb2312\"\r\n\r\n";
	sendBuff += content;
	sendBuff += "\r\n\r\n";
	return Send(sendBuff);
}

bool CSmtp::SendEnd()
{
	string sendBuff;
	sendBuff = "--qwertyuiop--";
	sendBuff += "\r\n.\r\n";
	if (false == Send(sendBuff) || false == Recv())
	{
		return false;
	}
	cout << buff << endl;
	sendBuff.empty();
	sendBuff = "QUIT\r\n";
	return (Send(sendBuff) && Recv());
}

int CSmtp::SendEmail_Ex()
{
	if (false == CreateConn())
		return 1;
	int err = Login();
	if (err != 0)
		return err;
	if (false == SendEmailHead())
		return 1;
	if (false == SendTextBody())
		return 1;
	if (false == SendEnd())
		return 1;
	return 0;
}