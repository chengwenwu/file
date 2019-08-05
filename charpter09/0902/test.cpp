#include <stdio.h>
#include <pthread.h>
class Hello{
public:
    static void* say_hello(void* args){
	/*�̵߳����к���������void*��û˵�ı�ʾ����ͨ��ָ�롢����ͨ��ָ��*/
	    printf("hello from thread\n");
	    pthread_exit((void*)1);
    }
};
int main(){
	pthread_t tid;
    int iRet = pthread_create(&tid, NULL, Hello::say_hello, NULL);
	/*���������ǣ��������߳�id���̲߳��������ú�����������ĺ�������*/
    if (iRet){
	    printf("pthread_create error: iRet=%d\n",iRet);
	    return iRet;
    }
	void *retval;
	iRet=pthread_join(tid,&retval);
	if (iRet){
	    printf("pthread_join error: iRet=%d\n",iRet);
	    return iRet;
    }
	printf("retval=%ld\n",(long)retval);	
	return 0;
}
