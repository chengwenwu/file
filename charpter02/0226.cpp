#include<iostream>
#include<string>
using namespace std;
class CStudent{//��������Student
public:
   CStudent(int n,string nam,char s){//���๹�캯��
      num=n;
      name=nam;
      sex=s;
   }
   ~CStudent(){} //������������
protected: //��������
   int num;
   string name;
   char sex ;
};
class CStudent1: public CStudent{//����������Student1
public : //������Ĺ��ò���
   CStudent1 (int n,string nam,char s,int a,string ad): CStudent (n,nam,s){//�����๹�캯��
      age=a; //�ں�������ֻ�����������������ݳ�Ա��ʼ��
      addr=ad;
   }
   void show(){
      cout<<"num: "<<num<<endl;
      cout<<"name: "<<name<<endl;
      cout<<"sex: "<<sex<<endl;
      cout<<"age: "<<age<<endl;
      cout<<"address: "<<addr<<endl<<endl;
   }
   ~CStudent1(){ } //��������������
private : //�������˽�в���
   int age;
   string addr;
};
int main(){
   CStudent1 stud1(10010,"Wang-li",'f',19,"115 Beijing Road,Shanghai");
   CStudent1 stud2(10011,"Zhang-fun",'m',21,"213 Shanghai Road,Beijing");
   stud1.show(); //�����һ��ѧ��������
   stud2.show(); //����ڶ���ѧ��������
   return 0;
}
