#include<iostream>
using namespace std;

int main()
{
    // n = n-1 + sn-2

    
    int n = 10;
    int a =0;
    int b = 1;
    cout<<a<<" "<<b<<" ";

    for(int i= 1; i<=n; i++){

        int nextN = a+b;
        cout<<nextN<<" ";

        a = b;
        b = nextN;
    }
    return 0;
}