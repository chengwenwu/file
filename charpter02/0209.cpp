#include <iostream>
using namespace std;
class Box{
public:
    Box();//����һ���޲εĹ��캯��
    /*����һ���вεĹ��캯�������ò����ĳ�ʼ���б�����ݳ�Ա��ʼ��*/
    Box(int h,int w,int l):height(h),width(w),length(l){}
    int volume();
private:
    int height,width,length;
};
Box::Box(){//�����޲εĹ��캯��
    height=1;
    width=2;
    length=3;
}
int Box::volume(){
    return height*width*length;
}
int main(){
    Box box1;//��ָ��ʵ��
    cout<<"box1's volume: "<<box1.volume()<<endl;
    Box box2(2,5,10);//ָ��ʵ��
    cout<<"box2's volume: "<<box2.volume()<<endl;
    return 0;
}
