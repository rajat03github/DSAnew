#include <bits/stdc++.h>
using namespace std;

void reverseArray(vector<int> &arr, int m)
{
    // 0th indexing hai islie 1 ka use kro
    int s = m + 1;
    int e = arr.size() - 1;

    while (s <= e)
    {
        swap(arr[s], arr[e]);
        s++;
        e--;
    }
}