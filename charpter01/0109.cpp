#include<iostream>
using namespace std;
int main(){
    int a=2;
    int &r=a;
    a=a+4;
    cout<<a<<" "<<r<<endl;//��Ϊa��r��ֵ��ͬʱ�仯������a��r��ֵ����6��
    r=10;
    cout<<a<<" "<<r<<endl; //r���ˣ�aҲ��䣬����a��r��ֵ����10��
    return 0;
}
