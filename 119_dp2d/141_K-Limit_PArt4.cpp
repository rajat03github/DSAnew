#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(int index, int operationNo, int k, vector<int> &prices)
    {
        // base case
        if (index == prices.size())
            return 0;

        if (operationNo == 2 * k) // K is transaction limit
            return 0;

        int profit = 0;
        if (operationNo % 2 == 0)
        {
            // Buy allowed
            int BuyThis = -prices[index] + solve(index + 1, operationNo + 1, k, prices);

            int Skipthis = 0 + solve(index + 1, operationNo, k, prices);

            // Max of Buy or ignore
            profit = max(BuyThis, Skipthis);
        }
        else
        {
            // Max of Sell or ignore
            profit = max((prices[index] + solve(index + 1, operationNo + 1, k, prices)), (0 + solve(index + 1, operationNo, k, prices)));
        }
        return profit;
    }
    // TOP DOWN

    int TD(int index, int operationNo, int k, vector<int> &prices, vector<vector<int>> &dp)
    {
        // base case
        if (index == prices.size())
            return 0;

        if (operationNo == 2 * k) // K is transaction limit
            return 0;

        if (dp[index][operationNo] != -1)
            return dp[index][operationNo];

        int profit = 0;
        if (operationNo % 2 == 0)
        {
            // Buy allowed
            int BuyThis = -prices[index] + TD(index + 1, operationNo + 1, k, prices, dp);

            int Skipthis = 0 + TD(index + 1, operationNo, k, prices, dp);

            // Max of Buy or ignore
            profit = max(BuyThis, Skipthis);
        }
        else
        {
            // Max of Sell or ignore
            profit = max((prices[index] + TD(index + 1, operationNo + 1, k, prices, dp)), (0 + TD(index + 1, operationNo, k, prices, dp)));
        }
        return dp[index][operationNo] = profit;
    }

    // Bottom UP :
    int BU(int k, vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2 * k + 1, 0));

        for (int index = prices.size() - 1; index >= 0; index--)
        {
            for (int operationNo = 0; operationNo < 2 * k; operationNo++)
            {
                int profit = 0;
                if (operationNo % 2 == 0)
                {
                    // Buy allowed
                    int BuyThis = -prices[index] + dp[index + 1][operationNo + 1];

                    int Skipthis = 0 + dp[index + 1][operationNo];

                    // Max of Buy or ignore
                    profit = max(BuyThis, Skipthis);
                }
                else
                {
                    // Max of Sell or ignore
                    profit = max((prices[index] + dp[index + 1][operationNo + 1]), (0 + dp[index + 1][operationNo]));
                }
                dp[index][operationNo] = profit;
            }
        }
        return dp[0][0];
    }

    // Space OPT Bottom Up

    int SO(int k, vector<int> &prices)
    {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2 * k + 1, 0));

        vector<int> curr(2 * k + 1, 0);
        vector<int> next(2 * k + 1, 0);

        for (int index = prices.size() - 1; index >= 0; index--)
        {
            for (int operationNo = 0; operationNo < 2 * k; operationNo++)
            {
                int profit = 0;
                if (operationNo % 2 == 0)
                {
                    // Buy allowed
                    int BuyThis = -prices[index] + next[operationNo + 1];

                    int Skipthis = 0 + next[operationNo];

                    // Max of Buy or ignore
                    profit = max(BuyThis, Skipthis);
                }
                else
                {
                    // Max of Sell or ignore
                    profit = max((prices[index] + next[operationNo + 1]), (0 + next[operationNo]));
                }
                curr[operationNo] = profit;
            }
            next = curr;
        }
        return next[0];
    }

    int maxProfit(int k, vector<int> &prices)
    {
        // return solve(0, 0, k, prices);

        vector<vector<int>> dp(prices.size(), vector<int>(2 * k, -1));

        // return TD(0, 0, k, prices, dp);

        // return BU(k, prices);

        return SO(k, prices);
    }
};