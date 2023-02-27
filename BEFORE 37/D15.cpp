// BOOK ALLOCATION USING BINARY SEARCH
#include <iostream>
using namespace std;

bool isPossible(arr, int n , int m , int mid ){

int studentCount = 1;
int pageSum = 0;

for (int i = 0;
     i < n;
     i++;)
     {
        if( pageSum + arr[i]<= mid){
            // possible solution
            pageSum + arr[i];
        }
        else
        {
            studentCount++;
            // pagesum is 0 now for new student
            pageSum = arr[i];

            if(studentCount > m || arr[i]> mid)
            { //not possible sol
                return false;
            }
        }
     }
        return true ; 
}


    int s = 0;
int sum = 0;

for (int i = 0; i < n; i++)
{
    sum += arr[i];
}
int e = sum;
int ans = -1;

int mid = s + (e - s) / 2;

while (s <= e)
{
    if (isPossible(arr, n, m, mid))
    {
        ans = mid;
        e = mid - 1;
    }
    else
    {
        s = mid + 1;
    }
    mid = s + (e - s) / 2;
}
    return ans;