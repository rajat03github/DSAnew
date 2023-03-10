#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Bottom Up
    int lengthOfLongestAP(int A[], int n)
    {
        if (n <= 2)
            return n;
        int ansLength = 0;

        unordered_map<int, int> dp[n + 1];

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = A[i] - A[j];
                int cnt = 1;

                // check if ans already present
                if (dp[j].count(diff))
                    cnt = dp[j][diff];

                dp[i][diff] = 1 + cnt;
                ansLength = max(ansLength, dp[i][diff]);
            }
        }
        return ansLength;
    }
};

// REC + MEM
/*
int solve(int index, int diff, int A[], unordered_map<int, int> dp[])
{
    // Backward Check
    if (index < 0)
        return 0;

    if (dp[index].count(diff))
        return dp[index][diff];

    int ansLength = 0;
    for (int ele = index - 1; ele >= 0; ele--)
    {
        if (A[index] - A[ele] == diff)
        {
            ansLength = max(ansLength, 1 + solve(ele, diff, A, dp));
        }
    }
    return dp[index][diff] = ansLength;
    */
/* REC+ MEM ********************
int lengthOfLongestAP(int A[], int n)
{
if (n <= 2)
    return n;

int ans = 0;

unordered_map<int, int> dp[n + 1];

// For last 2 elements of AP
for (int i = 0; i < n; i++)
{
    for (int j = i + 1; j < n; j++)
    {
        // adding 2 because of 2 already AP elements
        ans = max(ans, 2 + solve(i, A[j] - A[i], A, dp));
    }
}
return ans;
}

*/