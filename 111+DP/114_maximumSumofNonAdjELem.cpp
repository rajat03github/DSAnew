#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &nums, int index)
{
    // base case
    if (index < 0)
        return 0;
    if (index == 0) // index is now 0
        return nums[0];

    // include or exclude current indexs
    int include = solveRec(nums, index - 2) + nums[index];
    int exclude = solveRec(nums, index - 1) + 0;

    return max(include, exclude);
}

int solveRecMemo(vector<int> &nums, int index, vector<int> &dp)
{
    // base case
    if (index < 0)
        return 0;
    if (index == 0) // index is now 0
        return nums[0];

    if (dp[index] != -1)
        return dp[index];

    // include or exclude current indexs
    int include = solveRecMemo(nums, index - 2, dp) + nums[index];
    int exclude = solveRecMemo(nums, index - 1, dp) + 0;

    dp[index] = max(include, exclude);
    return dp[index];
}

int solveTabulation(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n + 1, -1);

    dp[0] = nums[0];
    // for remaining
    for (int i = 1; i <= n; i++)
    {
        int include = dp[i - 2] + nums[i];
        int exclude = dp[i - 1] + 0;
        dp[i] = max(include, exclude);
    }
    return dp[n];
}

int solveDPSpaceOpt(vector<int> &nums)
{
    int n = nums.size();

    // initialisation
    int prev2 = 0; // for less than 0
    int prev1 = nums[0];

    // for remaining
    for (int i = 1; i < n; i++)
    {
        int include = prev2 + nums[i];
        int exclude = prev1 + 0;

        int ans = max(include, exclude);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums)

{
    // int n = nums.size();
    // int ans = solveRec(nums, n - 1); // From right to left
    // return ans;

    // Memoization
    // int n = nums.size();
    // // dp stores the value of past subproblems
    // vector<int> dp(n + 1, -1);
    // return solveRecMemo(nums, n - 1, dp);

    // TABULATION
    return solveTabulation(nums);
}