#include<iostream>
using namespace std;
#define pi 3.1415
class Circle{
public:
    Circle(int r);//�β��б�
    double Area();
private:
    int radius;//���ݳ�Ա
};
Circle::Circle(int r){
    radius=r; 
}
double Circle::Area(){
    return pi*radius*radius;
}
int main(){
    Circle cir1(10);
    cout<<"cir1's area: "<<cir1.Area()<<endl;
    Circle cir2(1);
    cout<<"cir2's area: "<<cir2.Area()<<endl;
    return 0;
}
