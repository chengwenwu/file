#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> iVec;
    cout<<"������С:"<<iVec.size()<<"����:"<<iVec.capacity()<<endl;
	
	/*1��Ԫ��,��������Ϊ1*/
    iVec.push_back(1);
    cout<<"������С:"<<iVec.size()<<"����:"<<iVec.capacity()<<endl;
	
	/*2��Ԫ��,��������Ϊ2*/
    iVec.push_back(2);
    cout<<"������С:"<<iVec.size()<<"����:"<<iVec.capacity()<<endl;
	
	/*3��Ԫ��,��������Ϊ4*/
    iVec.push_back(3);
    cout<<"������С:"<<iVec.size()<<"����:"<<iVec.capacity()<<endl;
	
    /*4��Ԫ��,��������Ϊ4*/
    iVec.push_back(4);
	cout<<"������С:"<<iVec.size()<<"����:"<<iVec.capacity()<<endl;
	
    /*5��Ԫ��,��������Ϊ8*/	
    iVec.push_back(5);
    cout<<"������С:"<<iVec.size()<<"����:"<<iVec.capacity()<<endl;
	
    /*6��Ԫ��,��������Ϊ8*/	
    iVec.push_back(6);
    cout<<"������С:"<<iVec.size()<<"����:"<<iVec.capacity()<<endl;

    /*7��Ԫ��,��������Ϊ8*/	
    iVec.push_back(7);
    cout<<"������С:"<<iVec.size()<<"����:"<<iVec.capacity()<<endl; 

    /*8��Ԫ�أ� ��������Ϊ8*/	
    iVec.push_back(8);
    cout<<"������С:"<<iVec.size()<<"����:"<<iVec.capacity()<<endl;

    /*9��Ԫ�أ� ��������Ϊ16*/	
    iVec.push_back(9);
    cout<<"������С:"<<iVec.size()<<"����:"<<iVec.capacity()<<endl;

    /* vs2005/8 �����������Ƿ����ģ��� 
    9��Ԫ��   ����9 
    10��Ԫ�� ����13 */

    /* ����effective stl�е�����Ľ��� swap() */
    cout<<"������С:"<<iVec.size()<<"����:"<<iVec.capacity()<<endl;
    vector<int>(iVec).swap(iVec);

    cout<<"��ʱ��vector<int>����Ĵ�СΪ:"<<(vector<int>(iVec)).size()<<endl;
    cout<<"��ʱ��vector<int>���������Ϊ: " <<(vector<int>(iVec)).capacity()<<endl;
    cout<<"������,��ǰvector�Ĵ�СΪ:"<<iVec.size()<<endl;
    cout<<"������,��ǰvector������Ϊ:"<< iVec.capacity()<<endl;

    return 0;
}
