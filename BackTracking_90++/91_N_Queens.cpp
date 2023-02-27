#include <bits/stdc++.h>
using namespace std;

void addSol(vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    vector<int> temp;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            temp.push_back(board[i][j]);
        }
    }

    ans.push_back(temp);
}

bool isSafe(int row, int col, vector<vector<int>> &board, int n)
{
    int x = row;
    int y = col;

    // check for same row
    while (y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
    }
    // no need to check col because filling left to right with col + 1

    x = row;
    y = col;
    // check for diagonals
    while (x >= 0 && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
        x--;
    }

    x = row;
    y = col;
    // check for diagonals
    while (x < n && y >= 0)
    {
        if (board[x][y] == 1)
        {
            return false;
        }
        y--;
        x++;
    }
    return true;
}

void solve(int col, vector<vector<int>> &ans, vector<vector<int>> &board, int n)
{
    // base case (all clms filled)
    if (col == n)
    {
        // board mei jo character hain unko single array mei convert krke ans mei daaldo
        addSol(ans, board, n);
        return;
    }

    // solve 1 case rest will be taken cared by recurrison
    for (int row = 0; row < n; row++)
    {
        // is placing queen here is safe ? check
        if (isSafe(row, col, board, n))
        {
            // if placing queen is safe
            board[row][col] = 1;
            solve(col + 1, ans, board, n);
            // backtracking
            // remove queen
            board[row][col] = 0;
        }
    }
}

vector<vector<int>> nQueens(int n)
{
    // create board
    vector<vector<int>> board(n, vector<int>(n, 0));
    vector<vector<int>> ans;

    solve(0, ans, board, n);
    return ans;
}