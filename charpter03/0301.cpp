#include<iostream>
#include<stdlib.h>
using namespace std;
#define max_size 10
//�Ƚ��������Ĵ�С
//����ȽϺ������ش���0��qsort����Ϊa>b
//����ȽϺ������ص���0��qsort����Ϊa=b
//����ȽϺ�������С��0��qsort����Ϊa<b
int cmp(const void *a,const void *b){
    return *(int *)a-*(int *)b;
}
int main(){
    int arr[max_size];
    int n=0;
    //�ӱ�׼�����豸�ж���������ͬʱ�ۼ����������ֱ��������Ƿ���������Ϊֹ
    for(;;n++){
        cin>>arr[n];
    }
    qsort(arr,n,sizeof(int),cmp);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
