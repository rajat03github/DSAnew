#include<iostream>
// vector is dynamic array 
#include<vector>
using namespace std;

int main()
{
    
    vector<int>v ; 
    // initial size of vector is 0
    // if we know size already so we can do this
    // here 5 is size , 1 se initialize kiya hai
    vector<int>a(5,1);
    cout<<"print a "<<endl;
    for(int i: a ){
        cout<< i <<" "<< endl;
    }
    
    // copy krlu a 

    vector<int> last(a);
    
    cout<<"print last "<<endl;
    for(int i: last ){
        cout<< i <<" "<< endl;
    }

    cout<<"size "<<v.capacity()<<endl;

    v.push_back(1);
    cout<<"capacity "<<v.capacity()<<endl;
    v.push_back(2);
    cout<<"capacity "<<v.capacity()<<endl;
    v.push_back(3);
    // capacity is doubled due to putting 3 in 
    cout<<"capacity "<<v.capacity()<<endl;
    cout<<"size is "<<v.size()<<endl;


    // element at index
    cout<<"element at "<<v.at(2)<<endl;

    cout<<"first element "<<v.front()<<endl;
    cout<<"last elemet "<<v.back()<<endl;

    // pop back
    cout<<"before pop "<<endl;
    for(int i:v){
        cout<<i<<" ";

    }cout<<endl;

    v.pop_back();

    cout<<"after pop "<<endl;
    for(int i: v ){
        cout<<i<< " "<<endl;
    }

    // full clear 
// size will be 0 but capacity same rahegi
cout<<"before clear size "<<v.size()<<endl;

v.clear();

cout<<"after clear size "<<v.size()<<endl;


    return 0;
}