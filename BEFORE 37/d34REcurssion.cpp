#include<iostream>
using namespace std;

int factorial(int n ){
    cout<<n<<endl;
    // base case
    if(n==1){
        return 1;
    }

    /*int smallerProblem = factorial(n -1 );
    int biggerProblem = n * smallerProblem;
    return biggerProblem;
    */
//    can also be written as 
    return n * factorial(n-1);

}

int main()
{
    int n ;
    cin >> n;

    int ans = factorial(n);

    cout<<ans<<endl; 
    return 0;
}