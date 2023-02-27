#include <bits/stdc++.h>
using namespace std;

// signum function is also used
int signum(int a, int b)
{
    if (a == b)
        return 0;
    else if (a > b)
        return 1;
    else
        return -1;
}

void callMedian(int element, priority_queue<int> &maxi, priority_queue<int, vector<int>, greater<int>> &mini, int &median)
{
    switch (signum(maxi.size(), mini.size()))
    {
    // cases
    case 0:
        if (element > median)
        {
            mini.push(element);
            median = mini.top();
        }
        else // e < m
        {
            maxi.push(element);
            median = maxi.top();
        }
        break;

    case 1:
        if (element > median)
        {
            mini.push(element);
            median = (mini.top() + maxi.top()) / 2;
        }
        else // e < m
        {
            // step 1 : maintain 1 balance before push
            mini.push(maxi.top());
            maxi.pop();

            // step 2 : insert now and update median
            maxi.push(element);
            median = (mini.top() + maxi.top()) / 2;
        }
        break;

    case -1:
        if (element > median)
        {
            // step 1 : maintain 1 balance before push
            maxi.push(mini.top());
            mini.pop();

            // step 2 : insert now and update median
            mini.push(element);
            median = (mini.top() + maxi.top()) / 2;
        }
        else // e < m
        {
            maxi.push(element);
            median = (mini.top() + maxi.top()) / 2;
        }
        break;
    }
}
vector<int> findMedian(vector<int> &arr, int n)
{
    //  first we need max and min heaps
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap;

    // we need ans vector to store and a median
    vector<int> ans;
    int median = 0;

    // processing
    for (int i = 0; i < n; i++)
    {
        int element = arr[i];
        // median because pass by ref
        callMedian(element, maxheap, minheap, median);
        ans.push_back(median);
    }

    return ans;
}

// TC - o(NlogN)