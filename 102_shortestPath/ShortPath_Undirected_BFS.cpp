#include <bits/stdc++.h>
using namespace std;

vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    // create adjlist
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        // undirectd
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // do bfs
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;

    queue<int> q;

    // push source node into queue
    q.push(s);
    parent[s] = -1;    // marking source of first as -1 as we dont know the parent of it
    visited[s] = true; // mark source visited as true

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto neighbr : adj[front])
        {
            if (!visited[neighbr])
            {
                visited[neighbr] = true;
                parent[neighbr] = front;
                q.push(neighbr);
            }
        }
    }

    // parent array is now ready so shorted path is

    vector<int> ans;
    int currentNode = t; // t is destination
    ans.push_back(t);

    // backtrack destination to the parent
    while (currentNode != s)
    {
        currentNode = parent[currentNode];
        ans.push_back(currentNode);
    }

    // now need to reverse the answer
    reverse(ans.begin(), ans.end());

    return ans;
}
