#include<iostream>
using namespace std;


class Animal {
    public:
    int age;

    public:
    void speak(){
        cout<<"speak"<<endl;
    }
};

class dog: public Animal{


};

class GermanShepd: public dog{


};

int main(){
    dog d;
    d.speak();

    GermanShepd g;
    g.speak();
    
    return 0;
}