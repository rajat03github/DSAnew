#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int>v ;
    v.push_back(1);
    v.push_back(3);
    v.push_back(4);
    v.push_back(7);


    cout<<"finding any number easy "<<binary_search(v.begin(),v.end(), 7);

cout<<endl;
    // for lower bound

    cout<<"lower bound "<<lower_bound(v.begin(), v.end(),4) - v.begin()<<endl;
    cout<<"upper bound "<<upper_bound(v.begin(), v.end(),4) - v.begin()<<endl;

    int a= 3 ;
    int b=5 ;

    cout<<"max "<<max(a,b)<<endl;
    cout<<"min "<<min(a,b)<<endl;

    swap(a,b);
    cout<<"a - "<<a<<endl;

    string s = "abcd";
    reverse(s.begin(), s.end());
    cout<<s<<endl;

// rotate me beginn do fit batao kitna rotate krna hai and end dedo
    rotate(v.begin(), v.begin()+1, v.end());

    cout<<"after rotate "<<endl;
    for(int i:v ){
        cout<<i<<" "<<endl;
    }

   

    return 0;
}