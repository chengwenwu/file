#include <vector>
#include <iostream>
using namespace std;
int main(){
	int a[7]={1,2,3,4,5,6,7};
	vector<int> ivector(a,a+7);/*vector�ĸ�ֵ��������������һ��������û����ŷ���  ����ɸ�ֵ�������������������ʼ�����vector
   ��ʼ����ʽvector<elementType> intvec(begin,end);������������������ȥ���ǱȽ�ϰ�ߵġ�*/
	vector<int>::iterator iter;
	for (iter=ivector.begin();iter!=ivector.end();iter++){
		cout<<*iter<<" ";
	}
	cout<<endl;
	ivector[5]=1;
	/*����vector�ĸ�ֵ�������ʽ����ȥ���Ǻ�����һ����
    Ҳ������ôдivector.at(5)=1;���Ǿ��ǲ�ϰ��	*/
	cout<<ivector[5]<<endl<<ivector.size()<<endl;
	for (iter=ivector.begin();iter!=ivector.end();iter++){
	    cout<<*iter<<" ";
	}
	cout<<endl;
	for(int i=0;i<5;i++){
	    cout<<ivector[i]<<" ";
	}
	cout<<endl;
	return 0;
}
