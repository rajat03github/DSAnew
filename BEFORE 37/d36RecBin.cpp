#include<iostream>
using namespace std;

// recursion sorted

bool isSorted(int arr[] , int size){

    // base case
    if(size==0 || size ==1 )
        return true;
    
    if(arr[0]> arr[1]){
        return false;
    }
    else{
        bool remainPart = isSorted(arr+1 ,size - 1 );
        return remainPart;
    }

}

int main()
{
    int arr[5] = {2,4,6,8,9};
    int size = 5;

    bool ans = isSorted(arr , size);    

    if(ans){
        cout<<"array is sorted"<<endl;
    }
    else{
        cout<<"array is not sorted";
    }
    
    return 0;
}