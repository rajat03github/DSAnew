#include <bits/stdc++.h>
using namespace std;

int solveDPSpaceOpt(vector<int> &nums)
{
    int n = nums.size();

    // initialisation
    int prev2 = 0; // for less than 0
    int prev1 = nums[0];

    // for remaining
    for (int i = 1; i < n; i++)
    {
        int include = prev2 + nums[i];
        int exclude = prev1 + 0;

        int ans = max(include, exclude);
        prev2 = prev1;
        prev1 = ans;
    }
    return prev1;
}

int houseRobber(vector<int> &valueInHouse)
{
    int n = valueInHouse.size();

    if (n == 1)
        return valueInHouse[0];

    vector<int> firstIncluded, lastIncluded;
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            firstIncluded.push_back(valueInHouse[i]);
        if (i != 0)
            lastIncluded.push_back(valueInHouse[i]);
    }
    return max(solveDPSpaceOpt(firstIncluded), solveDPSpaceOpt(lastIncluded));
}