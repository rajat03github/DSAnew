#include<iostream>
using namespace std;


// GLOBAL VARIABLE
// DONT USE GLOBAL VARIABLE
int score = 15;


void a(int& i){

    cout<<score<<" in a "<<endl;
    // KOI BHI ChANGE KR SKTA HAI 
    score++ ;

    cout<<i<< endl;
    // b(i);
}

void b(int& i){

   cout<<score<<" in b "<<endl; 

    cout<<i<< endl;    

}

int main()
{
    // I want to share a var between void a and void b we use ref var

    cout<<score<<" in main "<<endl;

    int i = 5;
    a(i);
    b(i);
    
    return 0;
}