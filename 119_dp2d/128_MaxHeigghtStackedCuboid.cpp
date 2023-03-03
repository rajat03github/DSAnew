#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<int> base, vector<int> newBox)
    {
        if (newBox[0] <= base[0] && newBox[1] <= base[1] && newBox[2] <= base[2])
            return true;
        return false;
    }
    int SpaceOpti(int n, vector<vector<int>> &a)
    {
        vector<int> currRow(n + 1, 0);
        vector<int> nextRow(n + 1, 0);

        for (int curr = n - 1; curr >= 0; curr--)
        {
            for (int prev = curr - 1; prev >= -1; prev--)
            {
                int include = 0;
                if (prev == -1 || check(a[curr], a[prev])) // height
                    include = a[curr][2] + nextRow[curr + 1];

                // exclude
                int exclude = 0 + nextRow[prev + 1];

                currRow[prev + 1] = max(include, exclude);
            }
            nextRow = currRow;
        }
        return nextRow[0]; //-1 is not a valid index so - 1 + 1
    }

    int maxHeight(vector<vector<int>> &cuboids)
    {
        // step 1 : sort all dimension
        for (auto &a : cuboids)
            sort(a.begin(), a.end());
        // step 2 : sort all cuboids basis on w or l
        sort(cuboids.begin(), cuboids.end());

        // Step 3: use :LIS logic
        return SpaceOpti(cuboids.size(), cuboids);
    }
};