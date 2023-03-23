#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(string &a, string &b, int i, int j)
    {
        if (i == a.length())
        {
            return b.length() - j; // started with  0 , 0
        }
        if (j == b.length())
            return a.length() - i; // remaining character
        int ans = 0;
        if (a[i] == b[j])
            return solve(a, b, i + 1, j + 1);
        else
        {
            // insert
            int insertAns = 1 + solve(a, b, i, j + 1);
            // delete
            int deleteAns = 1 + solve(a, b, i + 1, j);
            // replace
            int replaceAns = 1 + solve(a, b, i + 1, j + 1);

            ans = min({insertAns, deleteAns, replaceAns});
        }
        return ans;
    }
    // Top down

    int TD(string &a, string &b, int i, int j, vector<vector<int>> &dp)
    {
        if (i == a.length())
        {
            return b.length() - j; // started with  0 , 0
        }
        if (j == b.length())
            return a.length() - i; // remaining character

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = 0;
        if (a[i] == b[j])
            return TD(a, b, i + 1, j + 1, dp);
        else
        {
            // insert
            int insertAns = 1 + TD(a, b, i, j + 1, dp);
            // delete
            int deleteAns = 1 + TD(a, b, i + 1, j, dp);
            // replace
            int replaceAns = 1 + TD(a, b, i + 1, j + 1, dp);

            ans = min({insertAns, deleteAns, replaceAns});
        }
        return dp[i][j] = ans;
    }

    // Bottom Up
    int Tabulation(string a, string b)
    {
        vector<vector<int>> dp(a.length() + 1, vector<int>(b.length() + 1, 0));
        // for rows
        for (int j = 0; j < b.length(); j++)
        {
            dp[a.length()][j] = b.length() - j;
        }
        // for col
        for (int i = 0; i < a.length(); i++)
        {
            dp[i][b.length()] = a.length() - i;
        }

        for (int i = a.length() - 1; i >= 0; i--)
        {
            for (int j = b.length() - 1; j >= 0; j--)
            {
                int ans = 0;
                if (a[i] == b[j])
                    ans = dp[i + 1][j + 1];
                else
                {
                    // insert
                    int insertAns = 1 + dp[i][j + 1];
                    // delete
                    int deleteAns = 1 + dp[i + 1][j];
                    // replace
                    int replaceAns = 1 + dp[i + 1][j + 1];

                    ans = min({insertAns, deleteAns, replaceAns});
                }
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
    // spaceOpt BU :

    int spaceOPT(string a, string b)
    {
        vector<int> curr(b.length() + 1, 0);
        vector<int> next(b.length() + 1, 0);

        // Base CASE for colms
        for (int j = 0; j < b.length(); j++)
        {
            next[j] = b.length() - j;
        }

        for (int i = a.length() - 1; i >= 0; i--)
        {
            for (int j = b.length() - 1; j >= 0; j--)
            {
                // catch from base case

                curr[b.length()] = a.length() - i;

                int ans = 0;
                if (a[i] == b[j])
                    ans = next[j + 1];
                else
                {
                    // insert
                    int insertAns = 1 + curr[j + 1];
                    // delete
                    int deleteAns = 1 + next[j];
                    // replace
                    int replaceAns = 1 + next[j + 1];

                    ans = min({insertAns, deleteAns, replaceAns});
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

    int minDistance(string word1, string word2)
    {
        // return solve(word1, word2, 0, 0);

        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n, vector<int>(m, -1));

        // return TD(word1, word2, 0, 0, dp);

        // return Tabulation(word1, word2);

        // CASES to handle
        if (word1.length() == 0)
            return word2.length();
        if (word2.length() == 0)
            return word1.length();

        return spaceOPT(word1, word2);
    }
};