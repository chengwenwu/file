class CStudent {
public:
    void display();//������Ҫ�ֺ�
private:
    int num;
    char name[20];
    int age;
};
void CStudent::display(){
    cout<<"num:"<<num<<endl;
    cout<<"name:"<<name<<endl;
    cout<<"age:"<<age<<endl;
}
