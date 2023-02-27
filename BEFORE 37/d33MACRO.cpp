#include<iostream>
using namespace std;


// case 2 (macro)


// no extra storage is taken
#define PI 3.14 //this is a macro

int main()
{
    int r = 5 ; 

    // case 1 
    // double pi = 3.14;

    double area = PI* r * r;
    // macro cannot be changed
    // PI = PI + 1;   
    cout<<"area is "<<area << endl;

    return 0;



}
// #define min(a, b ) (((a)<(b)) ? (a):(b))

