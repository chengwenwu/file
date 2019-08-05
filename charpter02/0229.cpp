#include <iostream>
#include <string>
using namespace std;
/*��������Box*/
class Box{
public:
   Box(int,int,int);  //�������캯��
   virtual void display();//�����������
protected:  //�ܱ�����Ա����������Է���
   int length,height,width;
};
/*Box���Ա������ʵ��*/
Box:: Box (int l,int h,int w){//���幹�캯��
   length =l;
   height =h;
   width =w;
}
void Box::display(){//�����������  
   cout<<"length:" << length <<endl;
   cout<<"height:" << height <<endl;
   cout<<"width:" << width <<endl;
}
/*��������������FilledBox*/
class FilledBox : public Box{
public:
   FilledBox (int, int, int, int, string);//�������캯��
   virtual void display();//�麯��
private:
   int weight;//����
   string fruit;//װ�ŵ�ˮ��
};
/* FilledBox���Ա������ʵ��*/
void FilledBox :: display(){//�����������
   cout<<"length:"<< length <<endl;
   cout<<"height:"<< height <<endl;
   cout<<"width:"<< width <<endl;
   cout<<"weight:"<< weight <<endl;
   cout<<"fruit:"<< fruit <<endl;
}
FilledBox:: FilledBox (int l, int h, int w, int we, string f ) : Box(l,h,w), weight(we), fruit(f){}
int main(){//������
   Box box(1,2,3);//����Student�����stud1
   FilledBox fbox(2,3,4,5,"apple");//����FilledBox�����fbox
   Box *pt = &box;//����ָ���������ָ�����pt
   pt->display( );
   pt = &fbox;
   pt->display( );
   return 0;
}
