import smtplib,os
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
import base64
import random
import datetime

def send_mail(recv):
    username='2252074916@qq.com'
    passwd='shwrqntcnlfudhjh'
    title='Dream注册验证码邮件'
    content='【Dream】您的验证码为'+''.join(random.sample('0123456789',4))+"，(10分钟内有效)，为了账户安全请勿向他人提供该验证码。感谢使用Dream！\n\n本邮件是系统自动发送，请勿直接回复！"
    ssl=True
    email_host='smtp.qq.com'
    port=25
    ssl_port=465
    '''
    :param username: 用户名
    :param passwd: 密码
    :param recv: 收件人
    :param title: 邮件标题
    :param content: 邮件正文
    :param ssl: 是否安全链接，默认为普通
    :param email_host: smtp服务器地址，默认为163服务器
    :param port: 非安全链接端口，默认为25
    :param ssl_port: 安全链接端口，默认为465
    '''
    msg = MIMEMultipart()
    #发送内容的对象
    msg.attach(MIMEText(content))#邮件正文的内容
    msg['Subject'] = title  # 邮件主题
    msg['From'] = username  # 发送者账号
    msg['To'] = recv  # 接收者账号列表
    if ssl:
        smtp = smtplib.SMTP_SSL(email_host,port=ssl_port)
    else:
        smtp = smtplib.SMTP(email_host,port=port)
    #发送邮件服务器的对象
    smtp.login(username,passwd)
    try:
        smtp.sendmail(username,recv,msg.as_string())
        pass
    except Exception as e:
        smtp.quit()
        return False
    else:
        smtp.quit()
        return True
        


# #login("ddd")
# if send_mail('2681595858@qq.com'):
#          print("邮件发送成功！")