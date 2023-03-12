#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void fill(vector<vector<int>> &image, int sr, int sc, int oldCol, int color)
    {
        if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != oldCol)
        {
            return;
        }

        image[sr][sc] = color;

        fill(image, sr - 1, sc, oldCol, color); // same col prev row
        fill(image, sr + 1, sc, oldCol, color); // same col next row
        fill(image, sr, sc + 1, oldCol, color); // same row next col
        fill(image, sr, sc - 1, oldCol, color); // same row prev col
    }

    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
    {
        if (image[sr][sc] == color)
            return image;

        fill(image, sr, sc, image[sr][sc], color);
        return image;
    }
};