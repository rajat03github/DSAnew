// multiple fixed static arrays ka use hota hai 
#include<iostream>
// include lib
#include<deque>
using namespace std;

int main()
{
    

        deque<int> d;

        d.push_back(1);
        d.push_front(2);

        for(int i: d){
            cout<<i<<" ";
        }

        // d.pop_back();
        // d.pop_front();

        // cout<<endl;
        // for(int i: d){
        //     cout<<i<<" ";
        // }


    cout<<"print first index elemet " <<d.at(1);

cout<<endl;
    cout<<"first element "<<d.front()<<endl;
    cout<<"last elemet "<<d.back()<<endl;



cout<<"empty at "<<d.empty()<<endl;

cout<<"befor erase "<<d.size()<<endl;

d.erase(d.begin(), d.begin()+1);

cout<<"after erase "<<d.size()<<endl;

 for(int i: d){
            cout<<i<<" ";
        }

    return 0;
}