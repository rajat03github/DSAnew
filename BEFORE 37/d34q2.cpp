#include<iostream>
using namespace std;

int power(int n ){

    cout<<n <<endl;
    // base case
    if(n == 0 )
        return 1;

    // recursive relation 
    int small = power(n-1);
    int big = 2 * small;

    return big; 

    // return 2*power(n-1)
}

int main()
{
    int n ;
    cin >> n ; 

    int ans = power(n); 

    cout<<ans<<endl;
    return 0;
}