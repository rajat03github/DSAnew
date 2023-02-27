#include<iostream>
#include<queue>
using namespace std;

int main(){

    // creating a queue
    queue<int> q ;
    
    q.push(12);
    cout<<"front is "<<q.front()<<endl;
    q.push(15);
    cout<<"front is "<<q.front()<<endl;
    q.push(22);
    cout<<"front is "<<q.front()<<endl;

    cout<<" AT LAST "<<q.back()<<endl;

    cout<<"the size of q is "<<q.size()<<endl;
    
    q.pop();
    cout<<"the size of q is "<<q.size()<<endl;

    if(q.empty() )
        cout<<"queue is empty ";
    else
        cout<<"queue is not empty ";
    return 0;
}