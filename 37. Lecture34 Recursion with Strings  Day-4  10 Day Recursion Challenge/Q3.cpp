#include<iostream>
using namespace std;

int power(int a, int b)
{
    // base case
    if(b == 0)
        return 1;
    if( b == 1)
        return a;
    
    // recursive
    int ans = power(a,b/2);
    //if b is even
    if(b%2 == 0){
        return ans * ans;
    }
    else{
        // if be is odd
        return a * ans * ans;
    }
}

int main()
{
    int a, b;
    cout<<"enter a and b :"<<endl;
    cin>>a>>b;

    int ans = power(a,b);

    cout<<"Anser is "<<ans;
    return 0;
}