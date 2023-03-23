//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

// } Driver Code Ends
/*
struct Job
{
    int id;	 // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
*/

class Solution
{
public:
    bool cmp(Job a, Job b)
    {
        return a.profit > b.profit;
    }

    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, cmp);

        int maxiDeadline = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            maxiDeadline = max(maxiDeadline, arr[i].dead);
        }
        vector<int> slots(maxiDeadline + 1, -1); // 1 based indexing

        int count = 0;
        int maxProfit = 0;

        for (int i = 0; i < n; i++)
        {
            int currProfit = arr[i].profit;
            int currJobId = arr[i].id;

            // Can i complete this job in deadline ?
            for (int j = min(maxiDeadline, arr[i].dead); j >= 1; j--)
            {
                if (slots[j] == -1)
                {
                    count++;
                    slots[j] = true;
                    maxProfit += currProfit;
                    break;
                }
            }
        }
        vector<int> ans;
        ans.push_back(count);
        ans.push_back(maxProfit);

        return ans;
    }
};

//{ Driver Code Starts.
// Driver program to test methods
int main()
{
    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;

        // size of array
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution ob;
        // function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}

// } Driver Code Ends