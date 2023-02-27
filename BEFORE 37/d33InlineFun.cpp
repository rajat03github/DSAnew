// inline function

#include<iostream>
using namespace std;

// void func(int a , int b){
//     a++;
//     b++;
//     cout<<a<<" "<<b << endl;
// }


// int func

inline int getMax(int& a, int& b){
    return (a>b) ? a : b;
}


int main()
{
    int a = 1, b = 2;
    // function is in stack space
    // func(a,b);

    int ans = 0;

    // if(a>b){
    //     ans = a;
    // }
    // else{
    //     ans = b;
    // }

    // TERTIORy OPERATOR
    
    cout<<a<<" "<<b<<endl;

    ans = getMax(a, b );

    cout<<ans<<endl;

    a = a+ 3;
    b = b+ 1 ;
    cout<<a<<" "<<b<<endl;

    ans = getMax(a, b );
    cout<<ans<<endl;



    
    return 0;
}