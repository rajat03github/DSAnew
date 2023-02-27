
// WITH DP
#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;

int solve(int n, vector<int> &dp)
{

    if (n == 0)
        return 1;

    if (n == 1)
        return 1;

    // step 3: returning the value if dp[n]!= -1;

    if (dp[n] != -1)
        return dp[n];

    // step 2 : Store the ans in dp vector

    dp[n] = ((solve(n - 2, dp) % mod) + (solve(n - 1, dp) % mod)) % mod;

    return dp[n];
}

int countDistinctWays(int nStairs)
{

    // step1 creation of dp vector

    vector<int> dp(nStairs + 1, -1);

    return solve(nStairs, dp);
}

// #include <bits/stdc++.h>
// using namespace std;

// int solve(int nStairs, int i)
// {
//     // i is current stair , nstairs is last stair
//     //  either 1 step or 2 step

//     // if ended up on last stair
//     if (nStairs < 0)
//         return 0;
//     if (nStairs == 0)
//         return 1; // jump on own
//     // for last stair
//     int ans = solve(nStairs - 1) + solve(nStairs - 2);
//     return ans;

//     // // base case
//     // if (i == nStairs)
//     //     return 1; // jump on own

//     // if (i > nStairs)
//     //     return 0;
//     // return (solve(nStairs, i + 1) + solve(nStairs, i + 2));
// }
// int countDistinctWays(int nStairs)
// {
//     int i = 0; // current stair
//     int ans = solve(nStairs, i);

//     // if ending
//     int ans = solve(nStairs);
//     return ans;
// }