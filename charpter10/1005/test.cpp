#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    /*forkһ���ӽ���*/
    pid_t pid = fork();
    if (pid > 0){/*������*/
        printf("in parent process, sleep for one miniute...zZ...\n");
        sleep(3);
        printf("after sleeping, and exit!\n");
    }
    else if(pid == 0){
	    /*�ӽ����˳�����Ϊһ����������*/
        printf("in child process, and exit!\n");
        exit(0);
    }
    return 0;
}
