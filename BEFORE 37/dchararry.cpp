#include<iostream>
using namespace std;

int main()
{
    int arr[5] = { 1 ,2,3,4,5};
    char ch[6] = "abcde";  


    // cout behaviour alag hai
    // address
    cout<<arr<<endl;
    // content
    cout<<ch<<endl;


    char *c = &ch[0];
    cout<<c<<endl;

    cout<<*c<<endl;
    cout<<&c<<endl;
    cout<<&ch<<endl;
    cout<<*ch<<endl;

    char temp = 'z';
    cout<<temp<<endl;

    char *p = &temp;
// null character jab tk nhi milega tab tk rukega nhi
    cout<<p<<endl;


















    return 0;
}