#include "Smtp.h"
#include <iostream>
using namespace std;

int main()
{
	CSmtp smtp(
		465,									/*smtp端口*/
		"smtp.qq.com",						/*smtp服务器地址*/
		"2252074916@qq.com",				        /*你的邮箱地址*/
		"shwrqntcnlfudhjh",					        /*邮箱密码*/
		email,					    /*目的邮箱地址*/
		"Dream注册验证码邮件",							/*主题*/
		"'【Dream】您的验证码为'，(10分钟内有效)，为了账户安全请勿向他人提供该验证码。感谢使用Dream！\n\n本邮件是系统自动发送，请勿直接回复！"		                /*邮件正文*/
	);

	int err;
	if ((err = smtp.SendEmail_Ex()) != 0)
	{
		if (err == 1)
			cout << "错误1: 由于网络不畅通，发送失败!" << endl;
		if (err == 2)
			cout << "错误2: 用户名错误,请核对!" << endl;
		if (err == 3)
			cout << "错误3: 用户密码错误，请核对!" << endl;
		if (err == 4)
			cout << "错误4: 请检查附件目录是否正确，以及文件是否存在!" << endl;
	}

	system("pause");
	return 0;
}