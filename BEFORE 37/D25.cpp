#include <iostream>
using namespace std;

// we need to give size of col
bool isPresent(int arr[][3], int target, int i, int j)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (arr[i][j] == target);
                
            return 1;
        }
    }
    return 0;
}
// to print row wise sum
void sum(int arr[][3], int i, int j)
{
    cout<<"Printing the sum "<<endl;
     for (int i = 0; i < 3; i++)
    {
        int sum =0;
        for (int j = 0; j < 3; j++)
        {
           sum += arr[i][j];
        }
        cout<<sum<< " ";
    }
    cout<<endl;

}
int main()
{
    // 2d array
    int arr[3][3];
    // int arr[3][4] ={ { 1, 11, 111 ,1111}, {2,22,222,2222}, {3,33,333,3333}};

    cout << "enter the elements " << endl;

    // takin input row wise
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }
    // for col wise
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cin >> arr[j][i];
    //     }
    // }

    // print
    cout << "Print the elements ";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // cout<<"eNter the element to search "<<endl;
    // int target;
    // cin>>target;

    // if(isPresent(arr, target, 3, 4 )){
    //     cout<<"element found "<<endl;

    // }
    // else{
    //     cout<<"not found ";
    // }
    
    sum(arr, 3,3 );

    return 0;
}