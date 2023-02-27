#include<iostream>
using namespace std;


void print(int arr[], int s , int e)
{
    for(int i= s ; i<=e ; i++){
        cout<<arr[i]<<" ";
    }
     cout<<endl;   
}


int binarySearch(int arr[], int s, int e, int key)
{

    cout<<endl;

    print(arr, s, e);
    // base case 
    // element not found
    if(s > e)
        return -1;

// MID 
    int mid = s + ( e- s) /2;
    cout<<"value of mid is "<<arr[mid]<<endl;

    
    //element found 
    if(arr[mid] == key){
        return true;
    }


    if(arr[mid]< key ){
      return binarySearch(arr , mid +1 , e , key );
    }
    else{
        return binarySearch(arr , s , mid - 1 , key );
    }

}

int main()
{
    int arr[12] = {2,4,6,10,14,18, 22 ,  38 , 49 , 55 , 222 , 5656};
    int size = 12;
    int key = 5656;

    cout<<"Present or not "<<binarySearch(arr , 0 , size-1 , key);

    return 0;
} 