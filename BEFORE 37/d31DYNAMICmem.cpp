#include<iostream>
using namespace std;


// mem will be cleared so bad practice
// int& func(int a)
// {
//     int num = a;
//     int& ans = num;
//     return ans;
// } 

// THIS MEM  WILL ALSO BE CLEARED

// int* fun(int n)
// {
//     // this is local variable
//     int *ptr = &n;
//     return ptr;
// }

void update(int a)
{
    // this is pass by value
    // new mem is created and a copy is formed
    a++;
}

// refrence variable
void update2(int &a)
{
    // this is pass by refernce
    // no new mem is created only a new name is given
    a++;
}



int main()
{




    /*
    int i = 5;  
    // creating refrence variable

    int &j = i;

    cout<<i<<endl;
    i++;
    cout<<j<<endl;
    j++;
    cout<<i<<endl;
    cout<<j++<<endl; //7->8
    // 8++ -> 9
    cout<<++i<<endl;
    */

   int a= 5;

   cout<<endl;
   cout<<"Before "<<a << endl;
   update(a);
   cout<<"After "<<a <<endl;
   cout<<endl;


   cout<<"Before "<<a << endl;
   update2(a);
   cout<<"After "<<a <<endl;


    return 0;
}