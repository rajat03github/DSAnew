/*There is one meeting room in a firm. There are N meetings in the form of (start[i], end[i]) where start[i] is start time of meeting i and end[i] is finish time of meeting i.
What is the maximum number of meetings that can be accommodated in the meeting room when only one meeting can be held in the meeting room at a particular time?*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        // Ending in ascending
        return a.second < b.second;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> given; // start , end

        for (int i = 0; i < n; i++)
        {
            pair<int, int> New = make_pair(start[i], end[i]);

            given.push_back(New);
        }
        sort(given.begin(), given.end(), cmp);

        int count = 1;
        int ansEnd = given[0].second;

        for (int i = 1; i < n; i++)
        {
            if (given[i].first > ansEnd)
            {
                count++;
                ansEnd = given[i].second;
            }
        }
        return count;
    }
};