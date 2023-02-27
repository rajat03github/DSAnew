#include <iostream>
using namespace std;

void sayingDigit(int n,string arr[])
{
    // base case
    if (n == 0)
        return;
    // processing
    int digit = n % 10;
    n = n / 10;

    // recursive call
    sayingDigit(n, arr);
    
    cout <<arr[digit] << " ";
}

int main()
{
    string arr[10] = {"zero", "one ", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

    int n;
    cin >> n;
    cout<<endl;
    sayingDigit(n, arr);
    cout<<endl;
    return 0;
}