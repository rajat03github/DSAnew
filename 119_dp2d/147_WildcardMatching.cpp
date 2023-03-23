// Leet Code Question  = 44. Wildcard Matching
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool solve(string &str, string &ptrn, int i, int j)
    {
        // Base case
        if (i < 0 && j < 0) // valid pattern
            return true;
        if (i >= 0 && j < 0) // invalid pattern
            return false;
        if (i < 0 && j >= 0)
        {
            for (int k = 0; k <= j; k++)
            {
                if (ptrn[k] != '*')
                    return false;
            }
            return true;
        }
        // MATCHES
        if (str[i] == ptrn[j] || ptrn[j] == '?')
            return solve(str, ptrn, i - 1, j - 1);

        else if (ptrn[j] == '*')
            return (solve(str, ptrn, i - 1, j) || solve(str, ptrn, i, j - 1));
        else
            return false;
    }

    // 1 based indexing top down

    bool Memo(string &str, string &ptrn, int i, int j, vector<vector<int>> &dp)
    {
        // Base case
        if (i == 0 && j == 0) // valid pattern
            return true;
        if (i > 0 && j == 0) // invalid pattern
            return false;
        if (i == 0 && j > 0)
        {
            for (int k = 1; k <= j; k++)
            {
                if (ptrn[k - 1] != '*')
                    return false;
            }
            return true;
        }
        if (dp[i][j] != -1)
            return dp[i][j];
        // MATCHES
        // 1 based indexing
        if (str[i - 1] == ptrn[j - 1] || ptrn[j - 1] == '?')
            return dp[i][j] = Memo(str, ptrn, i - 1, j - 1, dp);

        else if (ptrn[j - 1] == '*')
            return dp[i][j] = (Memo(str, ptrn, i - 1, j, dp) || Memo(str, ptrn, i, j - 1, dp));
        else
            return dp[i][j] = false;
    }
    // bottomUp
    bool solveTab(string &str, string &ptrn)
    {
        vector<vector<int>> dp(str.length() + 1, vector<int>(ptrn.length() + 1, 0));

        dp[0][0] = true;

        for (int i = 1; i < str.length(); i++)
        {
            dp[i][0] = false;
        }

        for (int j = 1; j <= ptrn.length(); j++)
        {
            int chck = 1;
            for (int k = 1; k <= j; k++)
            {
                if (ptrn[k - 1] != '*')
                {
                    dp[0][j] == false;
                    chck = -1;
                }
            }
            if (chck == 1)
                dp[0][j] = true;
        }
        for (int i = 1; i <= str.length(); i++)
        {
            for (int j = 1; j <= ptrn.length(); j++)
            {
                // 1 based indexing
                if (str[i - 1] == ptrn[j - 1] || ptrn[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];

                else if (ptrn[j - 1] == '*')
                    dp[i][j] = (dp[i - 1][j] || dp[i][j - 1]);
                else
                    dp[i][j] = false;
            }
        }
        return dp[str.length()][ptrn.length()];
    }
    // SPACE OPTIMISED

    bool spaceOPT(string &str, string &ptrn)
    {
        vector<int> prev(ptrn.length() + 1, 0);
        vector<int> curr(ptrn.length() + 1, 0);

        prev[0] = true;

        for (int i = 1; i < str.length(); i++)
        {
            curr[0] = false;
        }

        for (int j = 1; j <= ptrn.length(); j++)
        {
            int chck = 1;
            for (int k = 1; k <= j; k++)
            {
                if (ptrn[k - 1] != '*')
                {
                    prev[j] == false;
                    chck = -1;
                }
            }
            if (chck == 1)
                prev[j] = true;
        }
        for (int i = 1; i <= str.length(); i++)
        {
            for (int j = 1; j <= ptrn.length(); j++)
            {
                // 1 based indexing
                if (str[i - 1] == ptrn[j - 1] || ptrn[j - 1] == '?')
                    curr[j] = prev[j - 1];

                else if (ptrn[j - 1] == '*')
                    curr[j] = (prev[j] || curr[j - 1]);
                else
                    curr[j] = false;
            }
            prev = curr;
        }
        return prev[ptrn.length()];
    }

    bool isMatch(string s, string p)
    {
        // return solve(s, p, s.length() - 1, p.length() - 1); // starting from the end

        vector<vector<int>> dp(s.length() + 1, vector<int>(p.length() + 1, -1));
        // return Memo(s, p, s.length(), p.length(), dp);

        // return solveTab(s, p);

        return spaceOPT(s, p);
    }
};