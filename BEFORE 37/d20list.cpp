#include<iostream>
#include<list>
using namespace std;

int main()
{

    list<int>l;

    // copy of this list to new
    list<int> m(l);
    list<int> n(5, 1000);

     for(int i : n ){
        cout<<i<< " " ;
    }
    cout<<"size of list "<<n.size()<<endl;

    l.push_back(1);
    l.push_front(2);

    for(int i : l ){
        cout<<i<< " " ;
    }

    cout<<endl;    
    l.erase(l.begin());
    // begin is 2 
    cout<<"after erase "<<endl;


    for(int i : l ){
        cout<<i<< " " ;
    }

    cout<<"size of list "<<l.size()<<endl;





    return 0;
}