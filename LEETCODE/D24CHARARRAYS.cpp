#include <iostream>
using namespace std;

char toLowercase(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    else
    {

        // char = B
        // ch- A
        // B- A = 1
        // 1+a = b
        // this is how it is converted
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool checkPalindrome(char a[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s <= e)
    {
        if (toLowercase(a[s]) != toLowercase(a[e]))
        {
            return 0;
        }
        else
        {
            s++;
            e--;
        }
    }
    return 1;
}

void reverse(char name[], int n)
{
    int s = 0;
    int e = n - 1;

    while (s < e)
    {
        swap(name[s++], name[e--]);
    }
}

int getLength(char name[])
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }
    return count;
}

int main()
{
    char name[20];
    cout << "enter your name " << endl;
    // cin stops at tab space and new line
    cin >> name;

    // name[2] = '\0'; //\0 is null and output stops at null character

    cout << "Your name is ";
    cout << name << endl;
    int len = getLength(name);

    cout << "Length " << len << endl;
    reverse(name, len);
    cout << "Your name is ";
    cout << name << endl;

    cout << "Palindrome or not  " << checkPalindrome(name, len) << endl;

    cout << "character is " << toLowercase('b') << endl;
    cout << "character is " << toLowercase('C') << endl;
    return 0;
}