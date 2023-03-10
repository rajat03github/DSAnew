// minSwapstoMakeSequenceIncreasing
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int solve(vector<int> &nums1, vector<int> &nums2, int index, bool swapped)
    {
        // Base case
        if (index == nums1.size())
            return 0;
        int ans = INT_MAX;

        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        // catch
        if (swapped)
            swap(prev1, prev2);

        // no swap
        if (nums1[index] > prev1 && nums2[index] > prev2)
            ans = solve(nums1, nums2, index + 1, 0);
        // swap : when diagonally greater because not swapping real arrays
        if (nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1 + solve(nums1, nums2, index + 1, 1)); // 1+ solve because swapped is being added

        return ans;
    }
    // Rec + Memo : Top Down

    int solveMem(vector<int> &nums1, vector<int> &nums2, int index, bool swapped, vector<vector<int>> &dp)
    {
        // Base case
        if (index == nums1.size())
            return 0;

        if (dp[index][swapped] != -1)
            return dp[index][swapped];

        int ans = INT_MAX;

        int prev1 = nums1[index - 1];
        int prev2 = nums2[index - 1];

        // catch
        if (swapped)
            swap(prev1, prev2);

        // no swap
        if (nums1[index] > prev1 && nums2[index] > prev2)
            ans = solveMem(nums1, nums2, index + 1, 0, dp);

        // swap : when diagonally greater because not swapping real arrays

        if (nums1[index] > prev2 && nums2[index] > prev1)
            ans = min(ans, 1 + solveMem(nums1, nums2, index + 1, 1, dp)); // 1+ solve because swapped is being added

        return dp[index][swapped] = ans;
    }

    // Tabulation : Bottom Up
    int solveTab(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        for (int index = n - 1; index >= 1; index--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {
                int ans = INT_MAX;

                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                // catch
                if (swapped)
                    swap(prev1, prev2);

                // no swap
                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = dp[index + 1][0];

                // swap : when diagonally greater because not swapping real arrays

                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + dp[index + 1][1]); // 1+ solve because swapped is being added

                dp[index][swapped] = ans;
            }
        }
        return dp[1][0];
    }

    // Space Opt : Bottom Up
    int spaceOPT(vector<int> &nums1, vector<int> &nums2)
    {
        int n = nums1.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        int currSwap, Swap = 0;     // 1
        int currnoSwap, noSwap = 0; // 0

        for (int index = n - 1; index >= 1; index--)
        {
            for (int swapped = 1; swapped >= 0; swapped--)
            {
                int ans = INT_MAX;

                int prev1 = nums1[index - 1];
                int prev2 = nums2[index - 1];

                // catch
                if (swapped)
                    swap(prev1, prev2);

                // no swap
                if (nums1[index] > prev1 && nums2[index] > prev2)
                    ans = noSwap;

                // swap : when diagonally greater because not swapping real arrays

                if (nums1[index] > prev2 && nums2[index] > prev1)
                    ans = min(ans, 1 + Swap); // 1+ solve because swapped is being added
                if (swapped)
                    currSwap = ans;
                else
                    currnoSwap = ans;
            }
            Swap = currSwap;
            noSwap = currnoSwap;
        }
        // return currnoSwap;
        return min(Swap, noSwap);
    }

    int minSwap(vector<int> &nums1, vector<int> &nums2)
    {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);
        // it means that the previous indexes weere swapped or not
        bool swapped = 0;
        // return solve(nums1, nums2, 1, swapped); // 1 index because -1 is inserted
        int n = nums1.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        // return solveMem(nums1, nums2, 1, swapped, dp);
        // return solveTab(nums1, nums2);

        return spaceOPT(nums1, nums2);
    }
};