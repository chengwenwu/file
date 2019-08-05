#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#define P_FIFO "/tmp/p_fifo"
int main(int argc, char** argv){
	char cache[100];
	int fd;
	memset(cache,0, sizeof(cache));   /*��ʼ���ڴ�*/
	if(access(P_FIFO,F_OK)==0){  /*�ܵ��ļ�����*/
      	execlp("rm","-f", P_FIFO, NULL);  /*ɾ��*/
		printf("access.\n");
	}
	if(mkfifo(P_FIFO, 0777) < 0){
		printf("createnamed pipe failed.\n");
	}
	fd= open(P_FIFO,O_RDONLY|O_NONBLOCK); /*��������ʽ�򿪣�ֻ��*/
	while(1){
		memset(cache,0, sizeof(cache));
		if((read(fd,cache, 100)) == 0 ){ /*û�ж�������*/
		    printf("nodata:\n");
		}
		else{
                 printf("getdata:%s\n", cache); /*�������ݣ������ӡ*/
              }
		sleep(1);/*����1s*/
    }
    close(fd);
    return 0;
}
