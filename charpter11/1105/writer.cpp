#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/shm.h>
#include <errno.h>
#define SEM_KEY 4001
#define SHM_KEY 5678
union semun {
	int val;
};
int main(void){
	/*create a shm*/
	int semid,shmid;
	shmid = shmget(SHM_KEY,sizeof(int),IPC_CREAT|0666);
	if(shmid<0){
	  printf("create shm error\n");
	  return -1;
	}
	void * shmptr;
	shmptr =shmat(shmid,NULL,0);
	if(shmptr == (void *)-1){
	  printf("shmat error:%s\n",strerror(errno));
	  return -1;
	}
	int * data = (int *)shmptr;	
	semid = semget(SEM_KEY,2,0666);
	struct sembuf sembuf1;
	union semun semun1;
	while(1){
	  sembuf1.sem_num=1;/*����ָ���2���ź�����sem_num=1��*/
	  sembuf1.sem_op=-1;/*������-1����Ϊ��2���ź�����ʼֵΪ1���������治������*/
      sembuf1.sem_flg=SEM_UNDO;
	  semop(semid,&sembuf1,1);/*����*/
	  scanf("%d",data);  /*�û����ն���������*/
	  sembuf1.sem_num=0;/*����ָ���һ���ź���*/
	  sembuf1.sem_op=1;/*������1*/	
	  sembuf1.sem_flg=SEM_UNDO;
	  semop(semid,&sembuf1,1);/*ִ��+1�����Ƿ��֣�reader�����������ڵ�һ���ź���Ϊ0���޷���һ��������writer��Ϊ���1����reader������writer����ѭ�������ֵڶ����ź����Ѿ���Ϊ0���������ˣ����ǻص�reader*/
    }
	 return 0;
}
