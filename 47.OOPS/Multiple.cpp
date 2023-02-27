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

class Human{
    public:
    string color;

    public:
    void speak(){
        cout<<"speak"<<endl;
    }
};
// Multiple
class Both: public Animal, public Human{

};

int main(){
    Animal d;
    // ambiguity
    // d.speak();
    d.Animal::speak();

    Both g;
    g.Human::speak();
    
    return 0;
}