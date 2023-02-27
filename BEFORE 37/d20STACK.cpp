#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<string> s ;
    s.push("rajat ");
    s.push("rohit ");
    s.push("harrry ");
    // last in first out 
    // harry is last so it is top element

    cout<<"top element "<<s.top()<<endl;
// pop top element : harry 

    s.pop();
    cout<<"top element "<<s.top()<<endl;

    cout<<"size "<<s.size()<<endl;

    cout<<"empty ? "<<s.empty();


    return 0;
}