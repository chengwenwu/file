#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;
void print( vector<int>v ){
	vector<int>::iterator iter=v.begin();
	for(;iter!=v.end();iter++)
	    cout<<*iter<<" ";
	cout<<endl;
}
int main(){
    vector<int> v; //������������0��Ԫ��
    int values[] = {1,3,5,7};
    v.insert(v.end(), values+1, values+3);//������������2��Ԫ�طֱ�Ϊ:3,5
	print(v);
    v.push_back(9); //������������3��Ԫ�طֱ�Ϊ:3,5,9
	print(v);
    v.erase(v.begin()+1);//������������2��Ԫ�طֱ�Ϊ:3,9
	print(v);
    v.insert(v.begin()+1, 4);//������������3��Ԫ�طֱ�Ϊ:3,4,9
	print(v);
    v.insert(v.end()-1, 4, 6);//������������7��Ԫ�طֱ�Ϊ:3,4,6,6,6,6,9
	print(v);
    v.erase(v.begin()+1, v.begin()+3); //������������5��Ԫ�طֱ�Ϊ:3,6,6,6,9
	print(v);
    v.pop_back(); //������������4��Ԫ�طֱ�Ϊ:3,6,6,6
	print(v);
    v.clear();//������������0��Ԫ��
	print(v);
    if (true == v.empty()) //�������Ϊ�������"null"
    {
      std::cout<<"null"<<std::endl;
    }
    return 0;
}
