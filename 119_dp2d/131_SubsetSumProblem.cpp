#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(int index, int arr[], int N, int target)
    {

        // base case
        if (index >= N)
            return 0;
        if (target < 0)
            return 0;
        if (target == 0)
            return 1;

        int include = solve(index + 1, arr, N, target - arr[index]);
        int exclude = solve(index + 1, arr, N, target - 0);

        return include or exclude;
    }

    // Top Down : Rec + memo
    bool solveMem(int index, int arr[], int N, int target, vector<vector<int>> &dp)
    {

        // base case
        if (index >= N)
            return 0;
        if (target < 0)
            return 0;
        if (target == 0)
            return 1;

        if (dp[index][target] != -1)
            return dp[index][target];

        int include = solveMem(index + 1, arr, N, target - arr[index], dp);
        int exclude = solveMem(index + 1, arr, N, target - 0, dp);

        return dp[index][target] = include or exclude;
    }

    // Bottom UP
    bool solveTab(int arr[], int index, int N, int sum)
    {
        bool dp[N + 1][sum + 1];
        for (int i = 0; i < N + 1; i++)
            dp[i][0] = true;
        for (int i = 1; i <= sum; i++)
            dp[0][i] = false;

        for (int i = 1; i < N + 1; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - arr[i - 1]] || dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[N][sum];
    }

    // space OPT

    bool solvespace(int arr[], int index, int N, int sum)
    {
        // vector<vector<int>> dp(N + 1, vector<int>(total + 1, 0));

        vector<int> prev(sum + 1, 0);
        vector<int> curr(sum + 1, 0);

        prev[0] = 1;
        curr[0] = 1;

        for (int i = 1; i < N + 1; i++)
        {
            for (int j = 1; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                    curr[j] = prev[j - arr[i - 1]] || prev[j];
                else
                    curr[j] = prev[j];
            }
            prev = curr;
        }
        return curr[sum];
    }

    int equalPartition(int N, int arr[])
    {

        int total = 0;
        for (int i = 0; i < N; i++)
        {
            total += arr[i];
        }
        if (total % 2 != 0)
            return 0;
        int target = total / 2;
        // return solve(0, arr, N, target);

        // vector<vector<int>> dp(N, vector<int>(target + 1, -1));

        // return solveMem(0, arr, N, target, dp);
        // return solveTab(arr, 0, N, target);
        return solvespace(arr, 0, N, target);
    }
};