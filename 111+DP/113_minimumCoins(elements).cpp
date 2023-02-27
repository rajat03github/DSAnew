#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &coin, int amount)
{
    // base case
    if (amount == 0)
        return 0;
    if (amount < 0)
        return INT_MAX;

    int mini = INT_MAX;
    for (int i = 0; i < coin.size(); i++)
    {
        int ans = solveRec(coin, amount - coin[i]);
        if (ans != INT_MAX)
        {
            // 1 + because current coin is also considered
            mini = min(mini, 1 + ans);
        }
    }
    return mini;
}

int solveRecMem(vector<int> &coin, int amount, vector<int> &dp)
{
    // base cases
    if (amount == 0)
        return 0;
    if (amount < 0)
        return INT_MAX;
    // Step 3
    if (dp[amount] != -1)
        return dp[amount];

    int mini = INT_MAX;
    for (int i = 0; i < coin.size(); i++)
    {
        int ans = solveRec(coin, amount - coin[i]);
        if (ans != INT_MAX)
            mini = min(mini, 1 + ans);
    }
    // Step 2
    dp[amount] = mini;
    return dp[amount];
}

int solveTabu(vector<int> &coin, int amount)
{
    vector<int> dp(amount + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= amount; i++)
    {
        // Trying to solve for every amount figure from 1 to amount~ dependency of prev sub problems

        for (int j = 0; j < coin.size(); j++)
        {
            if (i - coin[j] >= 0 && dp[i - coin[j]] != INT_MAX) // checking INTMAX because add 1 and it should not overflow
                dp[i] = min(dp[i], 1 + dp[i - coin[j]]);
        }
    }
    if (dp[amount] == INT_MAX)
        return -1;
    return dp[amount];
}

int minimumElements(vector<int> &coin, int amount)
{
    // int ans = solveRec(coin, amount);
    // if (ans == INT_MAX)
    //     return -1;
    // return ans;

    //     // Memoization
    //     vector<int> dp(amount+ 1, -1);
    //     int ans = solveRecMem(coin, amount);

    //     if (ans == INT_MAX)
    //         return -1;
    //     else
    //         return ans;

    // With Bottom UP
    return solveTabu(coin, amount);
}
