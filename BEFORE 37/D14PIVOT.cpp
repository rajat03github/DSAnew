#include<iostream>
using namespace std;

int getPivot(int arr[], int n ){

    int s= 0;
    int e = n-1;
    int mid = s+ ( e-s )/2 ;

    while(s<e){
        if(arr[mid] >= arr[0] ) //here 0 is index 
        {
            s = mid + 1 ; 
        }
        else 
        {
            // if we dow mid - 1 then it will go to another line 
            e = mid;
        }
        mid = s+ ( e-s )/2 ;
    }
    return s; 
}

int main()
{
    int arr[5] = { 8 , 10 , 17 , 1 , 3};
    cout<< " PIVOT IS at index :  "<< getPivot(arr, 5 ) << endl;
    // answer will be INDEX 
    return 0;
}