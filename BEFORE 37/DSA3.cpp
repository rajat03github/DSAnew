#include<iostream>
using namespace std;

int main()
{
//   int a;
//   cin>>a;
  
//   cout<<"value of n : "<<n<<endl;
  
//   if a is +ve
// if(a>0)
// {
//     cout<<" a is positive"<<endl;
// }  
// else{
//     cout<<" this is -ve "<<endl;
// }
  
//   while loop for sum
    // int n;
    // cin>>n;

    // int i  = 1;
    // int sum = 0;

    // while(i<=n){
    //     sum = sum +i;
    //     i = i + 1;
    // }
    // cout<<"value of sum is: "<<sum<<endl;

// prime no.

    int n;
    cin>>n;

    int i =2;
    while(i<n) {
        // divide hogaya , not prime 
        if(n%i==0){
            cout<<"Not prime for "<<i<<endl;
        }
        else
        {
            cout<<"prime for "<<i<<endl;
        }
        i = i+1;
        
    }

    return 0;
}