// palindrome
#include<iostream>
using namespace std;

bool checkPal(string str, int i , int j )
{
    //base case 
    if(i > j )
        return true;
    if(str[i] != str[j]){

        return false;
    }
    else{
        //Recursive call
        return checkPal(str, i + 1 , j-1 );
    }

}

int main()
{

    string name = "aabbaa";
    cout<<endl;

    bool ans = checkPal(name , 0 , name.length()-1);

    if(ans ){
        cout<<"It is Pal";
    }
    else{
        cout<<"Not pal";
    }
    
    return 0;
}