#include<iostream>
using namespace std;
void Mmin1(int a,int b){
   int temp;
   if(a>b){
       temp=a;
       a=b;
       b=temp;
   }
}

void Mmin2(int &a,int &b){//������Ϊ�����Ĳ���
   int temp;
   if(a>b){
       temp=a;
       a=b;
       b=temp;
   }
}
int main(){
    int a=30,b=20;
    Mmin1(a,b);//
    cout<<a<<" "<<b<<endl;//a��b��ֵ���ֲ��䡣
    Mmin2(a,b);
    cout<<a<<" "<<b<<endl;//a��ֵ��20��b��ֵ��30. a��b��ֵ���޸���
    return 0;
}
