#include<iostream>
using namespace std;

class A{
    public:
    void func(){
        cout<<"Inside Function "<<endl;
    }
};

class B: public A{
    public:
void func2(){
        cout<<"Inside Function "<<endl;
    }
};
class C: public A{
    public:
void func3(){
        cout<<"Inside Function "<<endl;
    }
};
int main(){
    A a;
    a.func();
    B b;
    b.func( );
    b.func2();
    C c;
    c.func();
    c.func3();
    return 0;
}