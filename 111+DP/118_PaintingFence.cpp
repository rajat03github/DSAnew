#include <bits/stdc++.h>
using namespace std;
// in this we are using MOD
#define MOD 1000000007

int add(int a, int b)
{
    return (a % MOD + b % MOD) % MOD;
}

int multiply(int a, int b)
{
    return ((a % MOD) * (b % MOD)) % MOD;
}

int solve(int n, int k)
{
    // base case
    if (n == 1)
        return k;

    if (n == 2)
        // k + k *(k - 1)
        return add(k, multiply(k, k - 1));

    int ans = add(multiply(solve(n - 2, k), k - 1), multiply(solve(n - 1, k), k - 1));
    return ans;
}

int solveRECMEM(int n, int k, vector<int> &dp)
{
    // base case
    if (n == 1)
        return k;
    if (n == 2)
        return add(k, multiply(k, k - 1));

    // step 3
    if (dp[n] != -1)
        return dp[n];

    dp[n] = add(multiply(solveRECMEM(n - 2, k, dp), k - 1), multiply(solveRECMEM(n - 1, k, dp), k - 1));
    return dp[n];
}

int solveTABU(int n, int k)
{
    vector<int> dp(n + 1, 0);
    dp[1] = k;
    dp[2] = add(k, multiply(k, k - 1));

    // remaining
    for (int i = 3; i <= n; i++)
    {
        dp[i] = add(multiply(dp[i - 2], k - 1), multiply(dp[i - 1], k - 1));
    }
    return dp[n];
}

int SpaceOP(int n, int k)
{
    int prev2 = k;
    int prev1 = add(k, multiply(k, k - 1));

    // remaining
    for (int i = 3; i <= n; i++)
    {
        int ans = add(multiply(prev2, k - 1), multiply(prev1, k - 1));
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int numberOfWays(int n, int k)
{
    // Write your code here.
    // return solve(n, k);

    // vector<int> dp(n + 1, -1);
    // return solveRECMEM(n, k, dp);

    // return solveTABU(n, k);

    return SpaceOP(n, k);
}
