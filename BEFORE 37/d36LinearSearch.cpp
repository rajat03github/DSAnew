#include<iostream>
using namespace std;

void print(int *arr , int n )
{
    cout<<"size of array is "<< n <<endl;

    for(int i = 0; i< n ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;   
}

bool Linearsearch(int arr[] , int size , int key )
    {
        print(arr, size);
        // base case 
        if(size == 0)
            return false;
        
        if(arr[0] == key)
            return true;
        else{
            bool remainPart = Linearsearch(arr+ 1 ,size - 1 , key);
            return remainPart;
        }
    }

int main()
{
    int arr[5] = {2,4,6,8,9};
    int size = 5; 
    int key = 9;
    bool ans = Linearsearch(arr , size , key);

    if(ans= true){
        cout<<"Present "<<endl;
    }
    else //if false
    {
        cout<<"Absent"<<endl;
    }

    return 0;
}