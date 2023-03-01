#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int solve(vector<int> &obstacles, int currLane, int currPos)
    {
        int n = obstacles.size() - 1; // given obstacles size is n+1

        // base case
        if (currPos == n)
            return 0;

        if (obstacles[currPos + 1] != currLane)
        {
            return solve(obstacles, currLane, currPos + 1);
        }
        else
        {
            // Side Ways
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                // side ways jump done so + 1
                if (currLane != i && obstacles[currPos] != i)
                {
                    ans = min(ans, 1 + solve(obstacles, i, currPos));
                }
            }
            return ans;
        }
    }

    // Top Down :

    int solveMem(vector<int> &obstacles, int currLane, int currPos, vector<vector<int>> &dp)
    {
        int n = obstacles.size() - 1; // given obstacles size is n+1

        // base case
        if (currPos == n)
            return 0;

        if (dp[currLane][currPos] != -1)
            return dp[currLane][currPos];

        if (obstacles[currPos + 1] != currLane)
        {
            return solveMem(obstacles, currLane, currPos + 1, dp);
        }
        else
        {
            // Side Ways
            int ans = INT_MAX;
            for (int i = 1; i <= 3; i++)
            {
                // side ways jump done so + 1
                if (currLane != i && obstacles[currPos] != i)
                {
                    ans = min(ans, 1 + solveMem(obstacles, i, currPos, dp));
                }
            }
            dp[currLane][currPos] = ans;
            return dp[currLane][currPos];
        }
    }

    // Bottom Up :
    int solveTab(vector<int> &obstacles)
    {
        vector<vector<int>> dp(4, vector<int>(obstacles.size(), 1e9));
        int n = obstacles.size() - 1;

        // 4 ROWS
        dp[0][n] = 0;
        dp[1][n] = 0;
        dp[2][n] = 0;
        dp[3][n] = 0;

        for (int currPos = n - 1; currPos >= 0; currPos--)
        {
            for (int currLane = 1; currLane <= 3; currLane++)
            {
                if (obstacles[currPos + 1] != currLane)
                {
                    dp[currLane][currPos] = dp[currLane][currPos + 1];
                }
                else
                {
                    // Side Ways
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++)
                    {
                        // side ways jump done so + 1
                        if (currLane != i && obstacles[currPos] != i)
                        {
                            ans = min(ans, 1 + dp[i][currPos + 1]);
                        }
                    }
                    dp[currLane][currPos] = ans;
                }
            }
        }
        return min({dp[2][0], 1 + dp[1][0], 1 + dp[3][0]});
    }

    //  Space Optimized Bottom Up :

    int SpaceOpt(vector<int> &obstacles)
    {

        int n = obstacles.size() - 1;

        vector<int> curr(4, INT_MAX);
        vector<int> next(4, INT_MAX);

        // 4 ROWS
        // current depend on next
        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for (int currPos = n - 1; currPos >= 0; currPos--)
        {
            for (int currLane = 1; currLane <= 3; currLane++)
            {
                if (obstacles[currPos + 1] != currLane)
                {
                    curr[currLane] = next[currLane];
                }
                else
                {
                    // Side Ways
                    int ans = 1e9;
                    for (int i = 1; i <= 3; i++)
                    {
                        // side ways jump done so + 1
                        if (currLane != i && obstacles[currPos] != i)
                        {
                            ans = min(ans, 1 + next[i]);
                        }
                    }
                    curr[currLane] = ans;
                }
            }
            next = curr;
        }
        return min({next[2], 1 + next[1], 1 + next[3]});
    }
    int minSideJumps(vector<int> &obstacles)
    {
        // Acc to question starting position of frog is 2nd lane and 0th position

        // return solve(obstacles, 2, 0);

        // vector<vector<int>> dp(4, vector<int>(obstacles.size(), -1));
        // return solveMem(obstacles, 2, 0, dp);

        // return solveTab(obstacles);

        return SpaceOpt(obstacles);
    }
};