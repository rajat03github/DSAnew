// POINERS
#include<iostream>
using namespace std;
// POINTER DOESNT MAKE COPY it point to original address

int main()
{
    int num = 5;

    cout<<num<<endl;

    // address of operator = &

    cout<<"adrrs is "<< &num <<endl;

    int *ptr = &num ;
    cout<<"value and addres is "<< *ptr<<"\nand "<<ptr<<endl;

    double d =  4.3;
    double *d2 = &d;
    cout<<"value and addres is "<< *d2<<"\nand "<<d2<<endl;

    int n = 6;
        cout<<"before "<<n<<endl;
        // FOR INCREMENT

    int *n2 = &n;
    // n2++ is wrong , BRACKETS ARE IMP
    (*n2)++;
        cout<<"after "<<n<<endl;

// copy pointer to pointer
    // *n2 was pointer
    // int *q = n2;
    // cout<<n2<<" "<<q<<endl;
    // cout<<*n2<<" "<<*q<<endl;

    // two pointer 
    int **q = &n2;
    cout<<"the add of n2 is "<<&n2<<endl;
    cout<<"the add of n2 is "<<q<<endl;
    // *q will give value of n2 which is a pointer so it is yet an adrres cause * will not show &
    cout<<"the value at add q is "<<*q<<endl;
    cout<<"the value at add value of (add q) is "<<**q<<endl;

    return 0;
}