#include <bits/stdc++.h>
using namespace std;

int solve(int n, vector<int> &days, vector<int> &cost, int index)
{
    // Base Case
    if (index >= n)
        return 0;

    // 1 day pass
    int option1 = cost[0] + solve(n, days, cost, index + 1);

    int i;
    // 7 day pass
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;

    int option2 = cost[1] + solve(n, days, cost, i);

    // 30 days
    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;

    int option3 = cost[2] + solve(n, days, cost, i);

    return min(option1, min(option2, option3));
}

int solveMem(int n, vector<int> &days, vector<int> &cost, int index, vector<int> &dp)
{
    // Base Case
    if (index >= n)
        return 0;

    if (dp[index] != -1)
        return dp[index];

    // 1 day pass
    int option1 = cost[0] + solveMem(n, days, cost, index + 1, dp);

    int i;
    // 7 day pass
    for (i = index; i < n && days[i] < days[index] + 7; i++)
        ;

    int option2 = cost[1] + solveMem(n, days, cost, i, dp);

    // 30 days
    for (i = index; i < n && days[i] < days[index] + 30; i++)
        ;

    int option3 = cost[2] + solveMem(n, days, cost, i, dp);

    dp[index] = min(option1, min(option2, option3));
    return dp[index];
}

// bottom up

int solvetab(int n, vector<int> &days, vector<int> &cost)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;

    for (int k = n - 1; k >= 0; k--)
    {
        // 1 day pass
        int option1 = cost[0] + dp[k + 1];

        int i;
        // 7 day pass
        for (i = k; i < n && days[i] < days[k] + 7; i++)
            ;

        int option2 = cost[1] + dp[i];

        // 30 days
        for (i = k; i < n && days[i] < days[k] + 30; i++)
            ;

        int option3 = cost[2] + dp[i];

        dp[k] = min(option1, min(option2, option3));
    }
    return dp[0];
}

int solvewithSPaceOPT(vector<int> &days, vector<int> &cost)
{
    int ans = 0;

    // first = days[]
    // second = cost[]

    queue<pair<int, int>> week;
    queue<pair<int, int>> month;

    for (auto day : days)
    {
        // step 1 : remove expired days
        while (!month.empty() && month.front().first + 30 <= day)
            month.pop();
        while (!week.empty() && week.front().first + 7 <= day)
            week.pop();

        // step 2 : add cost for current days
        week.push({day, ans + cost[1]});
        month.push({day, ans + cost[2]});

        // step 3 : update ans
        ans = min(ans + cost[0], min(week.front().second, month.front().second));
    }
    return ans;
}

int minimumCoins(int n, vector<int> days, vector<int> cost)
{

    // return solve(n, days, cost, 0);

    // vector<int> dp(n + 1, -1);
    // return solveMem(n, days, cost, 0, dp);

    // return solvetab(n, days, cost);

    return solvewithSPaceOPT(days, cost);
}