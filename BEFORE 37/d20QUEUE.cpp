#include<iostream>
#include<queue>
using namespace std;
// first in first out
int main()
{
    
    queue<string> q;
    q.push("rajat ");
    q.push("rohit ");
    q.push("harrry ");

    cout<<"before after pop "<<q. size()<<endl;
    // first in first out
    cout<<"first element "<< q.front()<<endl;

    q.pop();

    cout<<"first element "<< q.front()<<endl;
    
    cout<<"size after pop "<<q. size()<<endl;











    return 0;
}