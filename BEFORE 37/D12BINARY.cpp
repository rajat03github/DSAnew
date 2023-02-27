#include<iostream>
using namespace std;

int binarysearch(int arr[], int size, int key) {
    
    int start = 0;
    int end = size -1;

    // int mid = (start + end )/2 ; 
    // agar yeh integer ki range se bahar na nikle islie pahle hi start ko hatadia aur add krlia 
    int mid = ( start + (end- start/2));
    

    while(start<=end) {

        if(arr[mid] == key){
            return mid;
        }
        if(key> arr[mid]){
            start = mid+1;
        }
        else{
            end = mid - 1;
        }

        // mid = ( start + end )/2;
        int mid = ( start + (end- start/2));

    }
    return -1;
}

int main()
{
    int even[6]= {2,4,6,8,10,12};
    int odd[5]= {3,5,7,9,11};

    int indexEVEN = binarysearch(even, 6 , 12);
    cout<<"Index of 12 is "<< indexEVEN << endl;

    int indexODD = binarysearch(odd, 5 , 34);
    cout<<"Index of  is "<< indexODD<< endl;


    return 0;
}