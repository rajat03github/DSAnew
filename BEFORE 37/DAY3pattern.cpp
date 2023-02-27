#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
        int i =1;
    //row is i 
        while (i<=n)
        {
            /* code */
            int j = 1;
            while (j<=n)
            {
                /* code */
                cout<< i;
                j = j+1;
            }
            cout<<endl;
            i = i+1;
            
        }
        
    return 0;
}