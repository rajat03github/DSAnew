#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // create adjList
    unordered_map<int, list<pair<int, int>>> adjlist; // node -> node with (weight)

    for (int i = 0; i < g.size(); i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        adjlist[u].push_back(make_pair(v, w));
        adjlist[v].push_back(make_pair(u, w));
    }

    // required Data structures

    vector<int> key(n + 1); // if node - 1 then index is also 1
    vector<bool> mst(n + 1);
    vector<int> parent(n + 1);

    // initialise these now

    for (int i = 0; i <= n; i++)
    {
        key[i] = INT_MAX; // infinity
        parent[i] = -1;   // we dont know parents yet
        mst[i] = false;   // no mst yet
    }

    // Algorithm !
    key[1] = 0;     // source node marked 0
    parent[1] = -1; // now parent would be -1

    for (int i = 0; i < n; i++)
    {
        int mini = INT_MAX;
        int u;

        // now find minimum node
        for (int v = 1; v <= n; v++)
        {
            if (mst[v] == false && key[v] < mini)
            {
                u = v;
                mini = key[v];
            }
        }
        // mark min node as true;
        mst[u] = true;

        // take adjnodes
        for (auto it : adjlist[u])
        {
            int v = it.first;
            int w = it.second;

            if (mst[v] == false && w < key[v])
            {
                parent[v] = u;
                key[v] = w;
            }
        }
    }

    // create answer
    vector<pair<pair<int, int>, int>> result;
    for (int i = 2; i <= n; i++)
    {
        result.push_back({{parent[i], i}, key[i]});
    }
    return result;
}
