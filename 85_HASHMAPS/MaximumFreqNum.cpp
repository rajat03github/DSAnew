#include <bits/stdc++.h>
using namespace std;

int maximumFrequency(vector<int> &arr, int n)
{
    unordered_map<int, int> count;

    int maxFreq = 0;
    int maxAns = 0;

    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
        maxFreq = max(count[arr[i]], maxFreq);
    }

    for (int i = 0; i < n; i++)
    {
        if (maxFreq == count[arr[i]])
        {
            maxAns = arr[i];
            break;
        }
    }
    return maxAns;
}