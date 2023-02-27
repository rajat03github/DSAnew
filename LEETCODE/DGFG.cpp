#include<iostream>
using namespace std;

char getMaxOccChr(string s){
    int arr[26] = {0};

    // created an array of count of characters 
    for( int i = 0; i<26; i++){
        char ch = s[i];
        // lower case 
        int number = 0 ;
        if(ch >= 'a' && ch<= 'z'){
            int number = ch -'a';
            

        }
        else{
            // upper  case 
            int number = ch -'A';
        }
        arr[number]++;
    }
    int maxi = -1, ans = 0;
    for(int i = 0; i<26; i++){
        if(maxi < arr[i]){
            ans = i ;
            maxi = arr[i];
        }
    }
    char finalANS = 'a' + ans;
    return finalANS;
}

int main()
{
    
    string s;
    cout<<"ENTER ";
    cin>>s;
    cout<<getMaxOccChr(s) << endl;

    return 0;
}