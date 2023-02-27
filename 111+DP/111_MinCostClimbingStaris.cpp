#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solvedWithDpUp(vector<int> &cost, int n, vector<int> &dp)
    {
        // Base case
        if (n == 0) // 0th stair
            return cost[0];
        if (n == 1) // 1st stair
            return cost[1];
        // step 3
        if (dp[n] != -1)
            return dp[n];

        // step 2 = memoization
        dp[n] = cost[n] + min(solvedWithDpUp(cost, n - 1, dp), solvedWithDpUp(cost, n - 2, dp));
        return dp[n];
    }
    // BOTTOM DOWN
    int solvedWithDpDown(vector<int> &cost, int n)
    {
        // step 1
        vector<int> dp(n + 1, -1);
        // step 2 = base analyse
        dp[0] = cost[0];
        dp[1] = cost[1];

        // Remaining Cases
        for (int i = 2; i <= n - 1; i++)
        {
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n - 1], dp[n - 2]);
    }

    // For Space Optimization
    int SolvewithSpaceOptimized(vector<int> &cost, int n)
    {
        // depending on prev 2 numbers
        int prev1 = cost[1];
        int prev2 = cost[0];

        for (int i = 2; i <= n - 1; i++)
        {
            int curr = cost[i] + min(prev1, prev2);
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);
    }

    int minCostClimbingStairs(vector<int> &cost)
    {
        int n = cost.size();
        // step 1
        vector<int> dp(n + 1, -1);
        int ans = min(solvedWithDpUp(cost, n - 1, dp), solvedWithDpUp(cost, n - 2, dp));
        return ans;
    }

    // without DP
    int solve(vector<int> &cost, int n)
    {
        // Base case
        if (n == 0) // 0th stair
            return cost[0];
        if (n == 1) // 1st stair
            return cost[1];

        // jis stair se aaye ho uski cost add kro and kaha se aaye ho uska minimum lelo
        int ans = cost[n] + min(solve(cost, n - 1), solve(cost, n - 2));
        return ans;
    }

    // int minCostClimbingStairs(vector<int> &cost)
    // {
    //     // cost[n] = 0 to n-1 indexes so there is no adding cost for n
    //     int n = cost.size();
    //     int ans = min(solve(cost, n - 1), solve(cost, n - 2));
    //     return ans;
    // }
};