#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, int buy, vector<int> &prices)
    {
        if (index == prices.size())
            return 0;
        // Check if Already bought
        int profit = 0;

        if (buy)
        {
            int BuyThis = -prices[index] + solve(index + 1, 0, prices);

            int Skipthis = 0 + solve(index + 1, 1, prices);

            // Max of Buy or ignore
            profit = max(BuyThis, Skipthis);
        }
        else
        {
            // Max of Sell or ignore
            profit = max((prices[index] + solve(index + 1, 1, prices)), (0 + solve(index + 1, 0, prices)));
        }
        return profit;
    }

    // Top Down: Rec + Mem
    int solveMem(int index, int buy, vector<int> &prices, vector<vector<int>> &dp)
    {
        if (index == prices.size())
            return 0;

        if (dp[index][buy] != -1)
            return dp[index][buy];

        // Check if Already bought
        int profit = 0;

        if (buy)
        {
            int BuyThis = -prices[index] + solveMem(index + 1, 0, prices, dp);

            int Skipthis = 0 + solveMem(index + 1, 1, prices, dp);

            // Max of Buy or ignore
            profit = max(BuyThis, Skipthis);
        }
        else
        {
            // Max of Sell or ignore
            profit = max((prices[index] + solveMem(index + 1, 1, prices, dp)), (0 + solveMem(index + 1, 0, prices, dp)));
        }
        return dp[index][buy] = profit;
    }

    // Bottom Up : tabulation

    int solveTab(vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));

        for (int index = prices.size() - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;

                if (buy)
                {
                    int BuyThis = -prices[index] + dp[index + 1][0];

                    int Skipthis = 0 + dp[index + 1][1];

                    // Max of Buy or ignore
                    profit = max(BuyThis, Skipthis);
                }
                else
                {
                    // Max of Sell or ignore
                    profit = max((prices[index] + dp[index + 1][1]), (0 + dp[index + 1][0]));
                }
                dp[index][buy] = profit;
            }
        }
        return dp[0][1];
    }
    // Space Opt Bottom Up

    int SpaceOpt(vector<int> &prices)
    {
        vector<int> curr(2, 0); // index
        vector<int> next(2, 0); // index + 1

        for (int index = prices.size() - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                int profit = 0;

                if (buy)
                {
                    int BuyThis = -prices[index] + next[0];

                    int Skipthis = 0 + next[1];

                    // Max of Buy or ignore
                    profit = max(BuyThis, Skipthis);
                }
                else
                {
                    // Max of Sell or ignore
                    profit = max((prices[index] + next[1]), (0 + next[0]));
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }
    int maxProfit(vector<int> &prices)
    {
        // return solve(0, 1, prices);

        vector<vector<int>> dp(prices.size(), vector<int>(2, -1)); // 2 colums for 0 or 1

        // return solveMem(0, 1, prices, dp);

        // return solveTab(prices);

        return SpaceOpt(prices);
    }
};