#include<iostream>
using namespace std;

int main()
{
    int prod = 1;
    int sum = 0;
    while(n!=0){

        int digit = n%10; 
        // n%10 is modulas means if 435 % 10 then remainder will be 5 and answer could be 45
         prod = prod* digit;
         sum = sum + digit;

         n= n/10;
    }
     int answer = prod - sum;
         
    return answer;
}