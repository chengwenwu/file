#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int global = 1; /*��ʼ����ȫ�ֱ���������data��*/
int main(void){
    pid_t pid;/*�洢����id*/
    int   stack = 1;/*�ֲ�����������ջ��*/
    int  *heap;/*ָ��ѱ�����ָ��*/
    heap = (int *)malloc(sizeof(int));
    *heap = 3;/*���ö��е�ֵ��3*/
    pid = fork();/*����һ���µĽ���*/
    if (pid < 0){
        perror("fail to fork");
        exit(-1);
    }
    else if (pid == 0){
        /*�ӽ��̣��ı������ֵ*/
        global++;
        stack++;
        (*heap)++;
        /*��ӡ��������ֵ*/
        printf("In sub-process, global: %d, stack: %d, heap: %d\n", global, stack, *heap);
        exit(0);
    }
    else{
        /*������*/
        sleep(2);/*����2���ӣ�ȷ���ӽ�����ִ����ϣ���ִ�и�����*/
        printf("In parent-process, global: %d, stack: %d, heap: %d\n", global, stack, *heap);
    }
    return 0;
}
