#include<iostream>
using namespace std;

int main()
{
    int m = n;
    int mask = 0;
    // edge case 
    if(n==0){
        return 1;
    }
    while(m!=0){
        mask = ( mask<<1) | 1; //<< is left shift
        m = m>>1; //>> is right shift
     }
     int ans= (~n) & mask;

    
    return ans;
}