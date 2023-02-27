#include <bits/stdc++.h>
using namespace std;

int solve(int n, int x, int y, int z)
{
    // base case
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN; // -infinity

    // for including x , y , z
    int a = solve(n - x, x, y, z) + 1;
    int b = solve(n - y, x, y, z) + 1;
    int c = solve(n - z, x, y, z) + 1;

    int ans = max(a, max(b, c));
    return ans;
}
int solveMemo(int n, int x, int y, int z, vector<int> &dp)
{
    // base case
    if (n == 0)
        return 0;
    if (n < 0)
        return INT_MIN; // -infinity

    // step 3
    if (dp[n] != -1)
        return dp[n];

    // for including x , y , z
    int a = solveMemo(n - x, x, y, z, dp) + 1;
    int b = solveMemo(n - y, x, y, z, dp) + 1;
    int c = solveMemo(n - z, x, y, z, dp) + 1;

    dp[n] = max(a, max(b, c));
    return dp[n];
}

int solveWithTab(int n, int x, int y, int z)
{
    // Bottom Up Approach
    vector<int> dp(n + 1, INT_MIN); // because INT MIN IS needed
    dp[0] = 0;

    // for remaining
    for (int i = 1; i <= n; i++)
    {
        if (i - x >= 0)
            dp[i] = max(dp[i], dp[i - x] + 1);
        if (i - y >= 0)
            dp[i] = max(dp[i], dp[i - y] + 1);
        if (i - z >= 0)
            dp[i] = max(dp[i], dp[i - z] + 1);
    }

    if (dp[n] < 0)
        return 0;
    return dp[n];
}
int cutSegments(int n, int x, int y, int z)
{
    // int ans = solve(n, x, y, z);
    // if (ans < 0)
    //     return 0;
    // return ans;

    // With Memoization
    // vector<int> dp(n + 1, -1); // n +1 because of 0 based indexing

    // int ans = solveMemo(n, x, y, z, dp);
    // if (ans < 0)
    //     return 0;
    // return ans;

    // With Tabulation
    return solveWithTab(n, x, y, z);
}