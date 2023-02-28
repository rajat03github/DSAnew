#include <bits/stdc++.h>
using namespace std;

class Solution

// i = 0
// j = n -  1

{
public:
    int solve(vector<int> &v, int i, int j)
    {
        // base case
        if (i + 1 == j) // only 2 nodes
            return 0;

        // to find k
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            ans = min(ans, v[i] * v[j] * v[k] + solve(v, i, k) + solve(v, k, j));
        }
        return ans;
    }
    // TOP DOWN :

    int solveMemo(vector<int> &v, int i, int j, vector<vector<int>> &dp)
    {
        // base case
        if (i + 1 == j) // only 2 nodes
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // to find k
        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++)
        {
            ans = min(ans, v[i] * v[j] * v[k] + solveMemo(v, i, k, dp) + solveMemo(v, k, j, dp));
        }
        dp[i][j] = ans;
        return dp[i][j];
    }
    // BOTTOM UP:

    int solveTab(vector<int> &v)
    {
        int n = v.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        // since it is Bottom to Up
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = i + 2; j < n; j++)
            {
                int ans = INT_MAX;
                for (int k = i + 1; k < j; k++)
                {
                    ans = min(ans, v[i] * v[j] * v[k] + dp[i][k] + dp[k][j]);
                }
                dp[i][j] = ans;
            }
        }
        // i = 0
        // j = n -  1
        return dp[0][n - 1];
    }

    int minScoreTriangulation(vector<int> &values)
    {
        int n = values.size();
        // return solve(values, 0, n - 1); // index 0 and last

        // vector<vector<int>> dp(n, vector<int>(n, -1));
        // return solveMemo(values, 0, n - 1, dp);

        return solveTab(values);
    }
};