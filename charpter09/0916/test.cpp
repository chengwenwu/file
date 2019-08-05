#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#define CUSTOMER_NUM 10
/* @Scene: ĳ��ҵӪҵ��ͬʱֻ�ܷ��������˿͡�
 * �ж���˿͵�����ÿ���˿�������ַ��񴰿��������͵ȴ���
 * ����п��õķ��񴰿ڣ��ͽ��ܷ��� */
/* ���ź�������Ϊȫ�ֱ������������̹߳��� */
sem_t sem;
/* ÿ���߳�Ҫ���е����� */
void * get_service(void *thread_id){
/* ע�⣺��������thread_id��ֵ����Ϊthread_id�Ƕ����߳���ѭ������i�����ã����������ϱ��޸�*/
    int customer_id = *((int *)thread_id);
    if(sem_wait(&sem) == 0) {
        usleep(100); /* service time: 100ms */
        printf("customer %d receive service ...\n", customer_id);
        sem_post(&sem);
    }
}
int main(int argc, char *argv[]){
    /*��ʼ���ź�������ʼֵΪ2����ʾ�������˿Ϳ���ͬʱ���շ��� */
    sem_init(&sem,0,2);
    /*Ϊÿ���˿Ͷ���һ���߳�id*/
    pthread_t customers[CUSTOMER_NUM];
    int i, iRet;
    /* Ϊÿ���˿�����һ���߳� */
    for(i = 0; i < CUSTOMER_NUM; i++){
        int customer_id = i;
        iRet = pthread_create(&customers[i], NULL, get_service, &customer_id);
        if(iRet){
            perror("pthread_create");
            return iRet;
        }
        else{
            printf("Customer %d arrived.\n", i);
        }
        usleep(10);
    }
    /* �ȴ����й˿͵��߳̽��� */
    /* ע�⣺��ط���������i��ѭ����������Ϊ�����߳������ڷ���i��ֵ */
    int j;
    for(j = 0; j < CUSTOMER_NUM; j++) {
        pthread_join(customers[j], NULL);
    }
    /*�����ź���*/
    sem_destroy(&sem);
    return 0;
}
