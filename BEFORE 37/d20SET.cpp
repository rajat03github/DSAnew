#include<iostream>
#include<set>
using namespace std;

int main()
{

    // same element kitne baar bhi dalo ek hi baar aayega


    set<int> s;

    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(5);
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(4);
    s.insert(4);
    s.insert(4);
    s.insert(4);
    s.insert(4);
    s.insert(4);
    s.insert(4);
    s.insert(6);


    for(auto i: s ){
        cout<< i <<" "<<endl;
    }

    cout<<"now erase "<<endl;

    set<int>::iterator it = s.begin();
    it++;

    s.erase(it);

    
    for(auto i: s ){
        cout<< i <<" "<<endl;
    }

    cout<<"count is " << s.count(-5)<<endl;

    set<int>::iterator itr = s.find(5);

    cout<<"valur present at itr "<<*itr<<endl;
    
    return 0;
}