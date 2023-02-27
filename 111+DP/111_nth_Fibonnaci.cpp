#include <bits/stdc++.h>
using namespace std;

// TOP DOWN

int fibonacciTOP(int n, vector<int> &dp)
{
    // base case
    if (n <= 1)
        return n;

    // step 3
    if (dp[n] != -1)
        return dp[n];
    // step 2
    dp[n] = fibonacciTOP(n - 1, dp) + fibonacciTOP(n - 2, dp);
    return dp[n];
}

// BOTTOM UP
int fibonacciBOTTOM(int n, vector<int> &dp)
{
    // step2
    dp[0] = 0;
    dp[1] = 1;

    // step 3 = remaining ke lie loop
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}

// SPace Optimisation
int fibonnaciSpaceOptimised(int n)
{
    int prev1 = 1;
    int prev2 = 0;

    if (n == 0)
        return n;

    for (int i = 2; i <= n; i++)
    {
        int curr = prev1 + prev2;
        // shift logic
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1; // because now updated
}

int main()
{
    int n;
    cin >> n;

    // step 1
    vector<int> dp(n + 1); // memoization (storing solutions) and also step 1 in BOTTOM UP

    for (int i = 0; i <= n; i++) // for TOPDOWN
        dp[i] = -1;

    cout << fibonacciTOP(n, dp) << endl;
    cout << fibonacciBOTTOM(n, dp) << endl;
    cout << fibonnaciSpaceOptimised(n) << endl;
    return 0;
}