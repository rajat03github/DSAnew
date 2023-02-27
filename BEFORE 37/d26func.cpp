#include<iostream>
using namespace std;

void print(int *p){
    cout<<p<<endl;
    cout<<*p<<endl;
}

void update(int *p){
    // p = p+1;
    // cout<<"inside function "<<p<<endl;

    *p = *p+1;


}

int getSum( int arr[] , int n )
{
    cout<<"size: "<<sizeof(*arr)<<endl;
    // sirf ek pointer pass ho rha hai 
    int sum = 0;
    for(int i = 0 ; i<n ; i++){
        sum+= arr[i];
    }
    return sum;
}






int main()
{
    int value = 5;
    int *p = &value;

    // print(p);
    
    update(p);
    cout<<*p<<endl;

    int arr[6] = {1,2,3,4,5,8};

    cout<<"sum is"<<getSum(arr , 5)<<endl;
    
    // can also work as
    cout<<"sum is"<<getSum(arr+ 2 ,3 )<<endl;
    
    return 0;
}