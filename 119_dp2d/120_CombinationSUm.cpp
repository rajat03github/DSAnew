#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &num, int tar)
{
    // Base case
    if (tar < 0)
        return 0;
    if (tar == 0)
        return 1;

    // trying all values
    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += solve(num, tar - num[i]);
    }
    return ans;
}

int solveMemo(vector<int> &num, int tar, vector<int> &dp)
{
    // Base case
    if (tar < 0)
        return 0;
    if (tar == 0)
        return 1;

    // step 3
    if (dp[tar] != -1)
        return dp[tar];

    // trying all values
    int ans = 0;
    for (int i = 0; i < num.size(); i++)
    {
        ans += solveMemo(num, tar - num[i], dp);
    }
    dp[tar] = ans;
    return dp[tar];
}

int Tabulation(vector<int> &num, int tar)
{
    vector<int> dp(tar + 1, 0);

    dp[0] = 1;

    // traversal from target 1 to Tar
    for (int i = 1; i <= tar; i++)
    {
        // traverse On num vector
        for (int j = 0; j < num.size(); j++)
        {
            if (i - num[j] >= 0) // for making valid index
                dp[i] += dp[i - num[j]];
        }
    }
    return dp[tar];
}

int findWays(vector<int> &num, int tar)
{
    // return solve(num, tar);

    // vector<int> dp(tar + 1, -1);
    // return solveMemo(num, tar, dp);

    return Tabulation(num, tar);
}