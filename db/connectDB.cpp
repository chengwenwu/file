#include <stdio.h>
#include <mysql.h>

int main(int argc,char *argv[])
{
    MYSQL conn;
    int res;
    mysql_init(&conn);
    if(mysql_real_connect(&conn,"localhost","root","root","mysql",0,NULL,CLIENT_FOUND_ROWS)) //"root":数据库管理员 "":root密码 "test":数据库的名字
    {
    　　printf("connect success!\n");
    　　res=mysql_query(&conn,"select * from Student;");
    　　if(res)
    　　{
       　　 printf("error\n");
    　　}
    　　else
    　　{
        　　printf("OK\n");
    　　}
    　　mysql_close(&conn);
    }
    return 0;
}