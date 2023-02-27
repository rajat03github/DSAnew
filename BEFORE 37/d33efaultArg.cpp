#include<iostream>
using namespace std;

// int start = 0  is default argument
// int start = x  is default argument
void printArr(int arr[] , int n , int start = 0 ){
    for(int i  = start ; i < n ; i ++ )
        {
        cout<<arr[i]<<endl;
        }
}

int main()
{
    int arr[5]= {1,4,7,8,9};
        // size is 5
    printArr(arr , 5 );
    cout<<endl;
    printArr(arr , 5 , 2 );


    return 0;
}