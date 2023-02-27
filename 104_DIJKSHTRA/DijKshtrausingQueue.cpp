#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int V, int edges, int S)
{
    queue<int> q;
    vector<int> dist(V, INT_MAX);
    dist[S] = 0;
    q.push(S);

    // Make Adjcent List
    vector<pair<int, int>> adj[V];
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        for (auto &i : adj[top])
        {
            if (dist[top] + i.second < dist[i.first])
            {
                dist[i.first] = dist[top] + i.second;
                q.push(i.first);
            }
        }
    }
    return dist;
}

// ~ PRIORITY QUEUE

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    vector<int> dist(vertices, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<vector<pair<int, int>>> adj(vertices);
    for (int i = 0; i < edges; i++)
    {
        adj[vec[i][0]].push_back(make_pair(vec[i][1], vec[i][2]));
        adj[vec[i][1]].push_back(make_pair(vec[i][0], vec[i][2]));
    }
    pq.push(make_pair(0, source));
    dist[source] = 0;
    while (pq.size() > 0)
    {
        int cur = pq.top().second;
        int distance = pq.top().first;
        pq.pop();
        for (auto node : adj[cur])
        {
            if (dist[cur] != INT_MAX && dist[cur] + node.second < dist[node.first])
            {
                dist[node.first] = dist[cur] + node.second;
                pq.push(make_pair(node.second, node.first));
            }
        }
    }
    return dist;
}