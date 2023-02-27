#include <bits/stdc++.h>
using namespace std;

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{

    // nodes starting from 1 so using n+1
    vector<int> dist(n + 1, 1e9); // initialise with any big number
    dist[src] = 0;                // initial 0

    for (int i = 1; i <= n; i++) // n-1 times
    {
        // traverse on edge list
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && ((dist[u] + wt) < dist[v]))
                dist[v] = dist[u] + wt;
        }
    }

    // check for negative cycle
    bool flag = 0;
    // once agai n-1 times
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] != 1e9 && ((dist[u] + wt) < dist[v]))
            flag = 1;
    }

    if (flag == 0)
    {
        return dist[dest];
    }

    return -1;
}