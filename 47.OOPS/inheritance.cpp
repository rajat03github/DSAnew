#include<iostream>
using namespace std;

class Human{
    private:
        int age;
    public:
        int height;
        int weight;

    int getAge(){
        return this->age;
    }
    void setWeight(int w){
        this->weight = w ; 
    }
};

class Male: private Human{
    public:
    string color;

    void sleep(){
        cout<<"Male Sleeping "<<endl;
    }
    // proceted can be accsd in child class
    int getHeight(){
    return this->height;
}
};

int main(){

    Male Nim;
    // cout<<Nim.height;
    cout<<Nim.getHeight();     //this can be accesd as function 


    // inheritnce
    // cout << Nim.age<<endl;
    // cout << Nim.weight<<endl;
    // cout << Nim.height<<endl;

    // cout << Nim.color<<endl;
    // Nim.sleep();
    // Nim.setWeight(85);
    // cout << Nim.weight<<endl;
    
    return 0;
}