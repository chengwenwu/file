#include <iostream>
using namespace std;
class Box{
public:
    Box(int h=2,int w=2,int l=2);//���������캯��ʱָ��Ĭ�ϲ���
    int volume();
private:
    int height,width,length;
};
Box::Box(int h,int w,int len){//�ڶ��庯��ʱ���Բ�ָ��Ĭ�ϲ���
    height=h;
    width=w;
    length=len;
}
int Box::volume(){
    return height*width*length;
}
int main(){
    Box box1(1);//��ָ����2��3��ʵ��
    cout<<"box1's volume: "<<box1.volume()<<endl;
    Box box2(1,3);// ��ָ����3��ʵ��
    cout<<"box2's volume: "<<box2.volume()<<endl;
    return 0;
}
