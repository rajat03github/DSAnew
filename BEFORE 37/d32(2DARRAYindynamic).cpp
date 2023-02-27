// mem location part 2
// creating 2d array using new int

#include<iostream>
using namespace std;

int main()
{   
    int row ;
    int n = row;
    cin>> n ; 

    int col;
    int m = col;
    cin>>m ;

    // creation  of and 2D array 
    
    int** arr = new int* [ n ];

    for(int i = 0 ; i <m ; i++ )
    {
        arr[i] = new int[m];

    }

    // taking input

    for(int i = 0; i< n ; i++)
    {
        for(int j = 0; j< m ; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout<<endl;
    
    // printing 
    for(int i = 0; i< n ; i++)
    {
        for(int j = 0; j< m ; j++)
        {
            cout << arr[i][j] <<" ";
        }
            cout<<endl;
    }

    // RELEASIN (DELETING) MEMORY
    
    for(int i = 0 ; i <m ; i++ )
    {
        // innner wale pahle delete kro
       delete [ ]arr[ i ];
    }

    //  ab baaki bahar wala array delete krdo
        delete [ ]arr;


    return 0;
}