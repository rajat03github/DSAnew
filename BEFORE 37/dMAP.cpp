#include<iostream>
#include<map>
using namespace std;

int main()
{
    map<int , string>m;

    m[1]= "ROHIT ";
    m[13]= "YEH LE ";
    m[2]= "RAKAT ";

    m.insert({5, "bheem"});

    for(auto i:m){
        cout<<i.first <<" "<<i.second<<endl;
    }

    cout<<"finding 13 = "<<m.count(13)<<endl;









    return 0;
}