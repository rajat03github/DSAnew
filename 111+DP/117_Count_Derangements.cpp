#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

long long int solveMemo(int n, vector<long long int> &dp)
{
    // base cases
    // here n is the number of elements and indexes
    if (n == 1)
        return 0; // only 1 elements n[0] = 0;
    if (n == 2)
        return 1;

    // step 3
    if (dp[n] != -1)
        return dp[n];

    // int ans = (((n - 1) % MOD) * ((countDerangements(n - 1) % MOD) + (countDerangements(n - 2) % MOD)) % MOD);

    dp[n] = (((n - 1) % MOD) * ((solveMemo(n - 1, dp) % MOD) + (solveMemo(n - 2, dp) % MOD)) % MOD);

    return dp[n];
}

long long int solveTab(int n)
{
    // BOTTOM UP
    vector<long long int> dp(n + 1, 0);
    dp[1] = 0;
    dp[2] = 1;
    // base cases
    // here n is the number of elements and indexes

    for (int i = 3; i <= n; i++)
    {
        long long int first = dp[i - 1] % MOD;
        long long int second = dp[i - 2] % MOD;

        long long int sum = first + second % MOD;

        long long int ans = ((i - 1) * sum) % MOD;
        dp[i] = ans;
    }
    return dp[n];
}

long long int solveSpaceOpt(int n)
{
    // BOTTOM UP
    long long int prev2 = 0;
    long long int prev1 = 1;
    // base cases
    // here n is the number of elements and indexes

    for (int i = 3; i <= n; i++)
    {
        long long int first = prev1 % MOD;
        long long int second = prev2 % MOD;

        long long int sum = first + second % MOD;

        long long int ans = ((i - 1) * sum) % MOD;
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

long long int countDerangements(int n)
{
    // vector<long long int> dp(n + 1, -1); // 0 based indexing
    // return solveMemo(n, dp);
    // return solveTab(n);

    return solveSpaceOpt(n);
}