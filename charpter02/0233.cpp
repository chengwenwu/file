#include<iostream>
using namespace std;
class CSingleton{
private:
	CSingleton(){   //���캯����˽�е�
	}
	static CSingleton *m_pInstance;
public:
	static CSingleton * GetInstance(){
        if(m_pInstance == NULL)  //�ж��Ƿ��һ�ε���
	        m_pInstance = new CSingleton();
	    return m_pInstance;
	}
};
CSingleton * CSingleton::m_pInstance=NULL;//��ʼ����̬���ݳ�Ա
int main(){
    CSingleton *s1= CSingleton::GetInstance();
    CSingleton *s2= CSingleton::GetInstance();
    if(s1==s2){
        cout<<"s1=s2"<<endl;  //�����ִ�н���������s1=s2
    }
    return 0;
}
