#include<iostream>
using namespace std;

class A{
    public:
    void sayHello(){
        cout<<"hello me ";
    }

    void sayHello(string name){
        cout<<"hello me "<<name;
    }

     int sayHello(int m ){
        cout<<"hello me "<<m;
        return 1;
    }

};
class B {
    public:
    int a ;
    int b ; 

    public:
    int add(){
        return a+b;
    }
    void operator +(B &obj){
        int value1 = this->a;
        int value2 = obj.a;
        cout<<value2-value1;
    }
    void operator ()(){
     cout<<"mei vracjet hu "<<this->a<<endl;
    }
};

int main(){
    // A obj;
    // obj.sayHello();
    // obj.sayHello("naaam hai mera");
    // obj.sayHello(22);

    B oj1, oj2;
    oj1.a = 4;
    oj2.a = 5;

    oj1+ oj2;

    oj1();
    return 0;
}