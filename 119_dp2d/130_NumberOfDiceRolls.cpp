//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    long long solve(int dice, int face, int target)
    {
        // base cases
        if (target < 0)
            return 0;
        if (dice == 0 && target != 0)
            return 0;
        if (dice != 0 && target == 0)
            return 0;
        if (dice == 0 && target == 0)
            return 1; // do nothing is 1

        int ans = 0;
        for (int i = 1; i <= face; i++)
        {
            ans = ans + solve(dice - 1, face, target - i);
        }
        return ans;
    }

    // Top Down :
    long long solveMem(int dice, int face, int target, vector<vector<int>> &dp)
    {
        // base cases
        if (target < 0)
            return 0;
        if (dice == 0 && target != 0)
            return 0;
        if (dice != 0 && target == 0)
            return 0;
        if (dice == 0 && target == 0)
            return 1; // do nothing is 1
        if (dp[dice][target] != -1)
            return dp[dice][target];

        long long ans = 0;
        for (int i = 1; i <= face; i++)
        {
            ans = ans + solveMem(dice - 1, face, target - i, dp);
        }
        dp[dice][target] = ans;
        return dp[dice][target];
    }

    // Bottom Up :
    long long solveTab(int d, int faces, int t)
    {
        vector<vector<long long>> dp(d + 1, vector<long long>(t + 1, 0));

        // After Analysing base cases
        dp[0][0] = 1;

        for (int dice = 1; dice <= d; dice++)
        {
            for (int target = 1; target <= t; target++)
            {
                long long ans = 0;
                for (int i = 1; i <= faces; i++)
                {
                    if (target - i >= 0)
                    {
                        ans = ans + dp[dice - 1][target - i];
                    }
                }
                dp[dice][target] = ans;
            }
        }
        return dp[d][t];
    }
    // Bottom Up : spaCe Optimized
    long long spaceOpt(int dice, int face, int target)
    {
        vector<long long> prev(target + 1, 0);
        vector<long long> curr(target + 1, 0);

        // base case
        prev[0] = 1;

        for (int d = 1; d <= dice; d++)
        {
            for (int t = 1; t <= target; t++)
            {
                long long ans = 0;

                for (int f = 1; f <= face; f++)
                {
                    if (t - f >= 0)
                        ans = ans + prev[t - f];
                }
                curr[t] = ans;
            }
            prev = curr;
        }
        return prev[target]; // returing dice and target
    }

    long long noOfWays(int M, int N, int X)
    {
        // return solve(N, M, X);

        // vector<vector<int>> dp(N + 1, vector<int>(X + 1, -1));
        // return solveMem(N, M, X, dp);

        // return solveTab(N, M, X);
        return spaceOpt(N, M, X);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int M, N, X;

        cin >> M >> N >> X;

        Solution ob;
        cout << ob.noOfWays(M, N, X) << endl;
    }
    return 0;
}
// } Driver Code Ends