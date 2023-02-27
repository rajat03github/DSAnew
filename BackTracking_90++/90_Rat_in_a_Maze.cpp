#include <bits/stdc++.h>
using namespace std;

bool isSafe(int newx, int newy, vector<vector<bool>> &visited, vector<vector<int>> &arr, int n)
{
    if ((newx >= 0 && newx < n) && (newy >= 0 && newy < n) && visited[newx][newy] != 1 && arr[newx][newy] == 1)
        return true;
    else
        return false;
}

void solve(int x, int y, vector<vector<int>> &arr, int n, vector<string> &ans, vector<vector<bool>> &visited, string path)
{

    // base case (destination reached)
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }

    // 4 movements DLRU

    // down
    if (isSafe(x + 1, y, visited, arr, n)) // x+1 , y
    {
        visited[x][y] = 1;
        // recursive calls
        solve(x + 1, y, arr, n, ans, visited, path + 'D');
        // wapas aate hue false krni hai wps for backtracking
        visited[x][y] = 0;
    }

    // Left
    if (isSafe(x, y - 1, visited, arr, n)) // x , y-1
    {
        visited[x][y] = 1;
        // recursive calls
        solve(x, y - 1, arr, n, ans, visited, path + 'L');
        // wapas aate hue false krni hai wps for backtracking
        visited[x][y] = 0;
    }

    // Right
    if (isSafe(x, y + 1, visited, arr, n)) // x , y+1
    {
        visited[x][y] = 1;
        // recursive calls
        solve(x, y + 1, arr, n, ans, visited, path + 'R');
        // wapas aate hue false krni hai wps for backtracking
        visited[x][y] = 0;
    }

    // up
    if (isSafe(x - 1, y, visited, arr, n)) // x-1 , y
    {
        visited[x][y] = 1;
        // recursive calls
        solve(x - 1, y, arr, n, ans, visited, path + 'U');
        // wapas aate hue false krni hai wps for backtracking
        visited[x][y] = 0;
    }
}

vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    string path = "";

    // if starting is 0 then
    if (arr[0][0] == 0)
        return ans;

    solve(0, 0, arr, n, ans, visited, path);
    return ans;
}