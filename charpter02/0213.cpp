#include<iostream>
using namespace std;
class CStudent{
public:
    CStudent (int n,int s):num(n),score(s){}//���幹�캯��
    void total();
    static double average();
private:
    int num;
    int score;
    static int count;
    static int sum;//���������ݳ�Ա�����ж������
};
int CStudent::count=0;//���徲̬���ݳ�Ա
int CStudent::sum=0;
void CStudent::total(){//����Ǿ�̬��Ա����
    sum+=score; //�Ǿ�̬���ݳ�Ա�����п�ʹ�þ�̬���ݳ�Ա���Ǿ�̬���ݳ�Ա
    count++;
}

double CStudent::average(){//���徲̬��Ա����
    return sum*1.0/count;//����ֱ�����þ�̬���ݳ�Ա�����ü�����
}
int main(){
    CStudent stu1(1,100);
    stu1.total();//���ö���ķǾ�̬��Ա����
    CStudent stu2(2,98);
    stu2.total();
    CStudent stu3(3,99);
    stu3.total();
    cout<< CStudent::average()<<endl;//������ľ�̬��Ա���������99
}
