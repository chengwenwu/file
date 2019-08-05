#include <iostream>
using namespace std;
template<class T>//����һ��ģ�壬����������ΪT
class Operation {
public:
    Operation (T a, T b):x(a),y(b){}
    T add(){
        return x+y;
    }
    T subtract(){
        return x-y;
    }
private:
    T x,y;
};
int main(){
    Operation <int> op_int(1,2);
    cout<<op_int.add()<<" "<<op_int.subtract()<<endl;//���3��-1
    Operation <double> op_double(1.2,2.3);
    cout<<op_double.add()<<" "<<op_double.subtract()<<endl;//���3.5��-1.1
    return 0;
}
