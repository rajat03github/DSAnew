#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &weight, vector<int> &value, int index, int MaxCapacity)
{
    // base case
    // last element moving from right to left
    // if only ONE item to steal then check capacity
    if (index == 0)
    {
        if (weight[0] <= MaxCapacity)
            return value[0];
        else
            return 0;
    }

    int include = 0;

    if (weight[index] <= MaxCapacity)
        include = value[index] + solve(weight, value, index - 1, MaxCapacity - weight[index]);

    int exclude = 0 + solve(weight, value, index - 1, MaxCapacity);
    int ans = max(include, exclude);

    return ans;
}

int solveMem(vector<int> &weight, vector<int> &value, int index, int MaxCapacity, vector<vector<int>> &dp)
{
    // base case
    // last element moving from right to left
    // if only ONE item to steal then check capacity
    if (index == 0)
    {
        if (weight[0] <= MaxCapacity)
            return value[0];
        else
            return 0;
    }

    if (dp[index][MaxCapacity] != -1)
        return dp[index][MaxCapacity];

    int include = 0;

    if (weight[index] <= MaxCapacity)
        include = value[index] + solveMem(weight, value, index - 1, MaxCapacity - weight[index], dp);

    int exclude = 0 + solveMem(weight, value, index - 1, MaxCapacity, dp);

    dp[index][MaxCapacity] = max(include, exclude);

    return dp[index][MaxCapacity];
}

int tabulation(vector<int> &weight, vector<int> &value, int n, int MaxCapacity)
{
    // step 1
    vector<vector<int>> dp(n, vector<int>(MaxCapacity + 1, 0));

    // step 2 : analyze base case
    for (int w = weight[0]; w <= MaxCapacity; w++)
    {
        if (weight[0] <= MaxCapacity)
            dp[0][w] = value[0];
        else
            dp[0][w] = 0;
    }

    for (int index = 1; index < n; index++)
    {
        for (int Wcol = 0; Wcol <= MaxCapacity; Wcol++)
        {
            int include = 0;

            if (weight[index] <= Wcol)
                include = value[index] + dp[index - 1][Wcol - weight[index]];

            int exclude = 0 + dp[index - 1][Wcol];

            dp[index][Wcol] = max(include, exclude);
        }
    }
    return dp[n - 1][MaxCapacity];
}

int space(vector<int> &weight, vector<int> &value, int n, int MaxCapacity)
{

    // step 1
    vector<int> prev(MaxCapacity + 1, 0);
    vector<int> curr(MaxCapacity + 1, 0);

    // step 2 : analyze base case
    for (int w = weight[0]; w <= MaxCapacity; w++)
    {
        if (weight[0] <= MaxCapacity)
            prev[w] = value[0];
        else
            prev[w] = 0;
    }
    // step 3 Remaning calls

    for (int index = 1; index < n; index++)
    {
        for (int Wcol = 0; Wcol <= MaxCapacity; Wcol++)
        {
            int include = 0;

            if (weight[index] <= Wcol)
                include = value[index] + prev[Wcol - weight[index]];

            int exclude = 0 + prev[Wcol];

            curr[Wcol] = max(include, exclude);
        }
        prev = curr;
    }
    return prev[MaxCapacity];
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    // return solve(weight, value, n - 1, maxWeight);

    // vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));
    // return solveMem(weight, value, n - 1, maxWeight, dp);

    // return tabulation(weight, value, n, maxWeight);
    return space(weight, value, n, maxWeight);
}
