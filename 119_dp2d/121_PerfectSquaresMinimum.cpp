//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
	int solve(int n)
	{
		// base case
		if (n == 0)
			return 0;

		int ans = n;
		for (int i = 1; i * i <= n; i++)
		{
			int temp = i * i;
			ans = min(ans, 1 + solve(n - temp));
		}

		return ans;
	}

	int solveMemo(int n, vector<int> &dp)
	{
		// base case
		if (n == 0)
			return 0;

		// step 3.
		if (dp[n] != -1)
			return dp[n];

		int ans = n;
		for (int i = 1; i * i <= n; i++)
		{
			int temp = i * i;
			ans = min(ans, 1 + solveMemo(n - temp, dp));
		}
		dp[n] = ans;
		return dp[n];
	}
	// bottom up

	int Tabulation(int n)
	{
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = 0;

		// remaining
		for (int i = 1; i <= n; i++)
		{
			int ans = n;
			for (int j = 1; j * j <= n; j++)
			{
				int temp = j * j;
				if (i - temp >= 0)
					dp[i] = min(dp[i], 1 + dp[i - temp]);
			}
		}
		return dp[n];
	}

	int MinSquares(int n)
	{
		// Code here
		// return solve(n);

		vector<int> dp(n + 1, -1);
		return Tabulation(n);
	}
};

//{ Driver Code Starts.
int main()
{
	int tc;
	cin >> tc;
	while (tc--)
	{
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.MinSquares(n);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends