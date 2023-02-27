#include<iostream>
using namespace std;

// making func
bool search(int arr[], int size, int key){

for (int i = 0; i <size; i++)
{
    /* code */
    if( arr[i]== key){
        return 1;
        // 1 is true
    }
}

    return 0 ;
    // 0 is false 


}

int main()
{
    int arr[10] = {5 , 7 , -2 , 10, 22, -2, 0, 5, 22, 1};

    // FIND 1
    cout<<"Enter the element to search "<<endl;
    int key;
    cin>>key;

    bool found = search(arr, 10, key);
    if(found){
        cout<<"Key is found"<<endl;
    }
 
    else{
     cout<<"Key is absent "<<endl;

    }
   
    return 0;
}