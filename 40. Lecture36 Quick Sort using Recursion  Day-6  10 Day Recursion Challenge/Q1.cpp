#include<iostream>
using namespace std;

// condition is p must be mid and left wale <p and right wale greater >p

int  partition(int arr[], int s, int e)
{
    int pivot = arr[s];

    int count = 0;
    // count kro kitne element chote hain pivot se
    // pivot ke ek element aage se chalao
    for(int i = s+1; i <=e ; i++ )
    {
        if(arr[i]<= pivot){
            count++;
        }   
    }
    // place pivot at right position
    //if pivot is 3 then index will be 0 + count ki ussey chote kitne aaye hai
    int pivotIndex = s + count;
    swap(arr[pivotIndex],arr[s]);

    // for to fullfil condn
    // left and right wala part sambhal lo
    int i = s;
    int j = e;

    while(i<pivotIndex && j > pivotIndex)
    {

        // if element is already in left jo chota hai 
        while(arr[i] < pivot){
            i++;
        }
        // if right part mei element hia jo badha hai pivot se
        while(arr[j] > pivot){
            j--;
        }
    // if koi element  left mei hai jo badha hai and koi right mei hai jo chota hia 
    // swap unko
        if(i<pivotIndex && j > pivotIndex){
        swap(arr[i],arr[j]);
        i++;
        j--;
        }

    }
    // return ans
    return pivotIndex;


}



void quickSort(int arr[], int s, int e){

    // base case 
//0 or 1 element hai toh sorted maanunga
    if(s>=e)
        return;
    // partion
    int p = partition(arr, s, e);
    
    // RECURSION
    // left part
    quickSort(arr , s , p-1);
    // right part
    quickSort(arr , p+1 , e);
}




int main(){
    
    int arr[6]= {2,4,1,6,9, 3};
    int n = 6;

    quickSort(arr , 0 , n-1);

    // print 
    for(int i =0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
     cout<<endl;

    return 0;
}