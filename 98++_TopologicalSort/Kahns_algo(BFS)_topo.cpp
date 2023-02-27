#include <bits/stdc++.h>
using namespace std;

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    // create adjlist

    unordered_map<int, set<int>> adjlist;

    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adjlist[u].insert(v);
    }

    // find all indegress
    vector<int> indegree(v);

    for (auto i : adjlist)
    {
        for (auto j : i.second)
            indegree[j]++;
    }

    // 0 indegress push
    queue<int> q;
    for (int i = 0; i < v; i++) // here v are the vertexs
    {
        if (indegree[i] == 0)
            q.push(i);
    }

    // do bfs

    vector<int> ans;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        // ans store krlo
        ans.push_back(front);

        // check neighbrs and indegree update

        for (auto neighbr : adjlist[front])
        {
            indegree[neighbr]--;
            if (indegree[neighbr] == 0)
                q.push(neighbr);
        }
    }
    return ans;
}