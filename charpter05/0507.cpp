#include<stdio.h>
#include<stdlib.h>
int g1=0, g2=0, g3=0;
int max(int i)
{
    int m1=0,m2,m3=0,*p_max;
    static int n1_max=0,n2_max,n3_max=0;
    p_max = (int*)malloc(10);
    printf("��ӡmax�����ַ\n");
    printf("in max: %x\n\n",max);
    printf("��ӡmax���������ַ\n");
    printf("in max: %x\n\n",&i);
    printf("��ӡmax�����о�̬������ַ\n");
    printf("%x\n",&n1_max); //��ӡ�����ر������ڴ��ַ
    printf("%x\n",&n2_max);
    printf("%x\n\n",&n3_max);
    printf("��ӡmax�����оֲ�������ַ\n");
    printf("%x\n",&m1); //��ӡ�����ر������ڴ��ַ
    printf("%x\n",&m2);
    printf("%x\n\n",&m3);
    printf("��ӡmax������malloc�����ַ\n");
    printf("%x\n\n",p_max); //��ӡ�����ر������ڴ��ַ
    if(i) return 1;
    else return 0;
}
int main(int argc, char **argv)
{
    static int s1=0, s2, s3=0;
    int v1=0, v2, v3=0;
    int *p;   
    p = (int*)malloc(10);
    printf("��ӡ��ȫ�ֱ���(�ѳ�ʼ��)���ڴ��ַ\n");
    printf("%x\n",&g1); //��ӡ��ȫ�ֱ������ڴ��ַ
    printf("%x\n",&g2);
    printf("%x\n\n",&g3);
    printf("======================\n");
    printf("��ӡ�����ʼ����main��ַ\n");
    printf("main: %x\n\n", main);
    printf("��ӡ���ε�ַ\n");
    printf("argv: %x\n\n",argv);
    printf("��ӡ����̬�������ڴ��ַ\n");
    printf("%x\n",&s1); //��ӡ����̬�������ڴ��ַ
    printf("%x\n",&s2);
    printf("%x\n\n",&s3);
    printf("��ӡ���ֲ��������ڴ��ַ\n");
    printf("%x\n",&v1); //��ӡ�����ر������ڴ��ַ
    printf("%x\n",&v2);
    printf("%x\n\n",&v3);
    printf("��ӡmalloc����Ķѵ�ַ\n");
    printf("malloc: %x\n\n",p);
    printf("======================\n");
    max(v1);
    printf("======================\n");
    printf("��ӡ�Ӻ�����ʼ��ַ\n");
    printf("max: %x\n\n",max);
    return 0;
}
