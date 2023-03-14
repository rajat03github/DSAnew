#include <bits/stdc++.h>
using namespace std;

class Solution
{
public: // Space Opt Bottom Up
    int SpaceOpt(vector<int> &prices, int fee)
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
                    int SellKro = prices[index] + next[1] - fee;

                    int SkipKaro = 0 + next[0];

                    // Max of Sell or ignore
                    profit = max(SellKro, SkipKaro);
                }
                curr[buy] = profit;
            }
            next = curr;
        }
        return next[1];
    }

    int maxProfit(vector<int> &prices, int fee)
    {
        return SpaceOpt(prices, fee);
    }
};