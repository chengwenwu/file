#include<iostream>
using namespace std;
int min(int a,int b){//�����min���Ǻ�������a��b���βΣ�
                         //����ֵ��һ��int����
   if(a<b)return a;
   else return b;
}
int main(){
   int a=10,b=1;
   cout<<min(a,b)<<endl;//�����a��b��ʵ��
   return 0;
}
