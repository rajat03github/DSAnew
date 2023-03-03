#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int n, int a[], int curr, int prev)
    {
        // Base case
        if (curr == n)
            return 0;

        // include
        int include = 0;
        if (prev == -1 || a[curr] > a[prev]) // first element or greater element
            include = 1 + solve(n, a, curr + 1, curr);

        // exclude
        int exclude = 0 + solve(n, a, curr + 1, prev);

        return max(include, exclude);
    }

    // Top Down :

    int solveMemo(int n, int a[], int curr, int prev, vector<vector<int>> &dp)
    {
        // Base case
        if (curr == n)
            return 0;

        if (dp[curr][prev + 1] != -1)
            return dp[curr][prev + 1];

        // include
        int include = 0;
        if (prev == -1 || a[curr] > a[prev]) // first element or greater element
            include = 1 + solveMemo(n, a, curr + 1, curr, dp);

        // exclude
        int exclude = 0 + solveMemo(n, a, curr + 1, prev, dp);

        dp[curr][prev + 1] = max(include, exclude);
        return dp[curr][prev + 1];
    }

    // Bottom UP :

    int solveTab(int n, int a[])
    {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || a[curr] > a[prev]) // first element or greater element
                    include = 1 + dp[curr + 1][curr + 1];

                // exclude
                int exclude = 0 + dp[curr + 1][prev + 1];

                dp[curr][prev + 1] = max(include, exclude);
            }
        }
        return dp[0][0]; //-1 is not a valid index so - 1 + 1
    }

    int SpaceOpti(int n, int a[])
    {
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || a[curr] > a[prev]) // first element or greater element
                    include = 1 + nextRow[curr + 1];

                // exclude
                int exclude = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0]; //-1 is not a valid index so - 1 + 1
    }

    int solveOptimal(int n, int a[])
    {
        if (n == 0)
            return 0;

        vector<int> ans;
        ans.push_back(a[0]);

        for (int i = 1; i < n; i++)
        {
            if (a[i] > ans.back())
                ans.push_back(a[i]);
            else
            {
                // find index of JUST greater element
                int index = lower_bound(ans.begin(), ans.end(), a[i]) - ans.begin();

                ans[index] = a[i];
            }
        }

        return ans.size();
    }

    int longestSubsequence(int n, int a[])
    {
        // return solve(n, a, 0, -1);

        // vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        // return solveMemo(n, a, 0, -1, dp);

        // return solveTab(n, a);

        // return SpaceOpti(n, a);

        return solveOptimal(n, a);
    }
};