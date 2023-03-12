#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right)
    {
        // Base case
        if (left == right) // leaf node
            return 0;

        int ans = INT_MAX;

        for (int i = left; i < right; i++)
        {
            ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + solve(arr, maxi, left, i) + solve(arr, maxi, i + 1, right));
        }
        return ans;
    }
    // Top Down : rec + mem
    int solveMem(vector<int> &arr, map<pair<int, int>, int> &maxi, int left, int right, vector<vector<int>> &dp)
    {
        // Base case
        if (left == right) // leaf node
            return 0;

        if (dp[left][right] != -1)
            return dp[left][right];

        int ans = INT_MAX;

        for (int i = left; i < right; i++)
        {
            ans = min(ans, maxi[{left, i}] * maxi[{i + 1, right}] + solveMem(arr, maxi, left, i, dp) + solveMem(arr, maxi, i + 1, right, dp));
        }
        return dp[left][right] = ans;
    }

    int mctFromLeafValues(vector<int> &arr)
    {
        map<pair<int, int>, int> maxi;

        for (int i = 0; i < arr.size(); i++)
        {
            maxi[{i, i}] = arr[i];
            for (int j = i + 1; j < arr.size(); j++)
            {
                maxi[{i, j}] = max(arr[j], maxi[{i, j - 1}]);
            }
        }
        // return solve(arr, maxi, 0, arr.size() - 1);

        vector<vector<int>> dp(arr.size() + 1, vector<int>(arr.size() + 1, -1));

        return solveMem(arr, maxi, 0, arr.size() - 1, dp);
    }
};