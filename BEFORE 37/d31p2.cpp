#include<iostream>
using namespace std;

int Sum(int *arr, int n )
{
    int sum = 0;
    for ( int i = 0; i< n ; i++)
    {
        sum += arr [i];
    }
    return sum ; 
}

// arr[i] = *(arr + i)

int main()
{
    
    // char ch = 'a';
    // cout<<sizeof(ch)<<endl;


    // char *c = &ch; 
    // // in WIN32 4 bytes are stored in pointer
    // cout<<sizeof(c)<<endl;

    // DYNAMIC MEMORY ALLOCATION OF ARRAY 
    // asking n at runtime 

    int  n ; 
    cin >> n;
    // variable size array 
    int* arr = new int [ n ];

    for(int i = 0; i< n ; i++)
    {
        cin>>arr[i];
    }
    
    int ans = Sum(arr , n );

    cout<<ans<<endl;    


    // STATICALLY

    // while(true)
    // {
    //     int i = 5;
    // }

    // THIS WILL CRASH MEMORY DYNAMICALLY
    // HEAP MEMORY WILL NOT BE FREE
    // PROGRAM WILL BE CRASHED BECAUSE OF FulL MEMORY
    // while(true)
    // {
    //     int* ptr = new int;
    // }


    // static memory will be free automatically
    // dynamic memory will not be free automatically
    // we use "delete " keyword
    // for array  - delete []arr ; 

    return 0;
} 