// reversing string 

#include<iostream>
using namespace std;

void reverse(string& str , int i , int j)
{
    cout<<"call for "<< str<< endl;
    // base case 
    if( i > j )
        return ;
    swap(str[i], str[j]);
    i++;
    j--;

    // recursion
    reverse(str , i , j);
}

int main()
{
    string name = "rajat";

    reverse(name, 0 , name.length()-1);

    cout<<name<<endl;

    return 0;
}