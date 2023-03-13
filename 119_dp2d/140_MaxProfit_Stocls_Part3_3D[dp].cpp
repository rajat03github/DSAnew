#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(int index, int buy, vector<int> &prices, int limit)
    {
        if (index == prices.size())
            return 0;

        if (limit == 0)
            return 0;
        // Check if Already bought
        int profit = 0;

        if (buy) // buy == 1
        {
            // LIMIT = Buy and Sell Both Done is 1 transaction

            int BuyThis = -prices[index] + solve(index + 1, 0, prices, limit);

            int Skipthis = 0 + solve(index + 1, 1, prices, limit);

            // Max of Buy or ignore
            profit = max(BuyThis, Skipthis);
        }
        else
        {
            // Max of Sell or ignore
            profit = max((prices[index] + solve(index + 1, 1, prices, limit - 1)), (0 + solve(index + 1, 0, prices, limit)));
        }
        return profit;
    }
    // Top down : Mem
    int solveMem(int index, int buy, vector<int> &prices, int limit, vector<vector<vector<int>>> &dp)
    {
        if (index == prices.size())
            return 0;

        if (limit == 0)
            return 0;

        if (dp[index][buy][limit] != -1)
            return dp[index][buy][limit];
        // Check if Already bought
        int profit = 0;

        if (buy) // buy == 1
        {
            // LIMIT = Buy and Sell Both Done is 1 transaction

            int BuyThis = -prices[index] + solveMem(index + 1, 0, prices, limit, dp);

            int Skipthis = 0 + solveMem(index + 1, 1, prices, limit, dp);

            // Max of Buy or ignore
            profit = max(BuyThis, Skipthis);
        }
        else
        {
            // Max of Sell or ignore
            profit = max((prices[index] + solveMem(index + 1, 1, prices, limit - 1, dp)), (0 + solveMem(index + 1, 0, prices, limit, dp)));
        }
        return dp[index][buy][limit] = profit;
    }
    // Bottom Up : tabulation
    int solveTab(vector<int> &prices)
    {
        vector<vector<vector<int>>> dp(prices.size() + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int index = prices.size() - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1; limit <= 2; limit++)
                {
                    int profit = 0;

                    if (buy) // buy == 1
                    {
                        // LIMIT = Buy and Sell Both Done is 1 transaction

                        int BuyThis = -prices[index] + dp[index + 1][0][limit];

                        int Skipthis = 0 + dp[index + 1][1][limit];

                        // Max of Buy or ignore
                        profit = max(BuyThis, Skipthis);
                    }
                    else
                    {
                        int SellKaro = prices[index] + dp[index + 1][1][limit - 1]; // limit will be less of 1 because buy and sell done and 1 transaction is complete

                        int SkipKaro = 0 + dp[index + 1][0][limit];

                        // Max of Sell or ignore
                        profit = max(SellKaro, SkipKaro);
                    }
                    dp[index][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }

    // Space Optimised : bottom Up

    int spaceOpt(vector<int> &prices)
    {
        vector<vector<int>> curr(2, vector<int>(3, 0)); // index

        vector<vector<int>> next(2, vector<int>(3, 0)); // index + 1

        for (int index = prices.size() - 1; index >= 0; index--)
        {
            for (int buy = 0; buy <= 1; buy++)
            {
                for (int limit = 1; limit <= 2; limit++)
                {
                    int profit = 0;

                    if (buy) // buy == 1
                    {
                        // LIMIT = Buy and Sell Both Done is 1 transaction

                        int BuyThis = -prices[index] + next[0][limit];

                        int Skipthis = 0 + next[1][limit];

                        // Max of Buy or ignore
                        profit = max(BuyThis, Skipthis);
                    }
                    else
                    {
                        int SellKaro = prices[index] + next[1][limit - 1]; // limit will be less of 1 because buy and sell done and 1 transaction is complete

                        int SkipKaro = 0 + next[0][limit];

                        // Max of Sell or ignore
                        profit = max(SellKaro, SkipKaro);
                    }
                    curr[buy][limit] = profit;
                }
            }
            next = curr;
        }
        return next[1][2];
    }

    int maxProfit(vector<int> &prices)
    {
        int limit = 2; // At most two transactions

        // return solve(0, 1, prices, limit);

        // 3D DP :
        vector<vector<vector<int>>> dp(prices.size(), vector<vector<int>>(2, vector<int>(3, -1))); // limit is from 0 to 3

        // return solveMem(0, 1, prices, limit, dp);

        // return solveTab(prices);

        return spaceOpt(prices);
    }
};