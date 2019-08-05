#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#define MAXFILE 65535
int main(){
	pid_t pc;
	int i,fd,len;
	char *buf="this is a Dameon\n";
	len = strlen(buf);
	pc = fork(); /*��һ��*/
	if(pc<0){
		printf("error fork\n");
		exit(1);
	}else if(pc>0){
		exit(0);
	}
	setsid(); /*�ڶ���*/
	chdir("/"); /*������*/
	umask(0); /*���Ĳ�*/
	for(i=0;i<MAXFILE;i++) /*���岽*/
	    close(i);
    while(1){
	if((fd=open("/tmp/dameon.log",O_CREAT|O_WRONLY|O_APPEND,0600))<0){
		perror("open");
		exit(1);
	}
	write(fd,buf,len+1);
	close(fd);
	sleep(10);
  }
  return 0;
}
