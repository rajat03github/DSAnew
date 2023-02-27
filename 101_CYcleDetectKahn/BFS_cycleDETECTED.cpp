// check cycle in directed
#include <bits/stdc++.h>
using namespace std;

int detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // create adjlist

    unordered_map<int, set<int>> adjlist;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first - 1;
        int v = edges[i].second - 1;

        adjlist[u].insert(v);
    }

    // find all indegress
    vector<int> indegree(n);

    for (auto i : adjlist)
    {
        for (auto j : i.second)
            indegree[j]++;
    }

    // 0 indegress push
    queue<int> q;
    for (int i = 0; i < n; i++) // here n are nodes
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // do bfs

    int count = 0;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // incrememnt of count
        count++;

        // check neighbrs and indegree update

        for (auto neighbr : adjlist[front])
        {
            indegree[neighbr]--;
            if (indegree[neighbr] == 0)
                q.push(neighbr);
        }
    }
    // if topo sort
    if (count == n)
        return false;
    else             // if not topo sort != n
        return true; // cycle present
}