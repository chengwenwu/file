#include<iostream>
using namespace std;
class Box{
public:
    Box(int h=2,int w=2,int l=2);
    ~Box(){//��������
        cout<<"Destructor called."<<endl;//���������������
    }
    int volume(){
        return height*width*length;
    }
private:
    int height,width,length;
};
Box::Box(int h,int w,int len){
    height=h;
    width=w;
    length=len;
}
int main(){
    Box box1;
    cout<<"The volume of box1 is "<<box1.volume()<<endl;
    cout<<"hello."<<endl;
    return 0;
}
