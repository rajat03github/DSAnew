#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, vector<int> &discovery, vector<int> &lowestReach, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adj, vector<int> &artiPoint, int &timer)
{
    visited[node] = true;
    discovery[node] = lowestReach[node] = timer++;
    int child = 0;

    for (auto neighbr : adj[node])
    {
        if (neighbr == parent)
            continue;
        else if (!visited[neighbr]) // not visited
        {
            dfs(neighbr, node, discovery, lowestReach, visited, adj, artiPoint, timer);

            // upadte lowestReach when return

            lowestReach[node] = min(lowestReach[node], lowestReach[neighbr]);

            // check ArtiPoint
            if (lowestReach[neighbr] >= discovery[node] && parent != -1)
            {
                artiPoint[node] = 1;
            }

            // increment of child
            child++;
        }
        else // node already visited and not parent
        {
            // back edge
            lowestReach[node] = min(lowestReach[node], discovery[neighbr]);
        }
    }
    if (parent == -1 && child > 1)
    {
        artiPoint[node] = 1;
    }
}
int main()
{
    int n = 5; // nodes
    int e = 5; // edges between nodes

    vector<pair<int, int>> edges;

    // Given Edges in the example !
    edges.push_back(make_pair(0, 3));
    edges.push_back(make_pair(3, 4));
    edges.push_back(make_pair(0, 4));
    edges.push_back(make_pair(0, 1));
    edges.push_back(make_pair(1, 2));

    // adjlist
    unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // requirements
    int timer = 0;
    vector<int> discovery(n);
    vector<int> lowestReach(n);
    unordered_map<int, bool> visited;
    vector<int> artiPoint(n, 0); // intialised with 0

    // initialise the data structures now
    for (int i = 0; i < n; i++)
    {
        discovery[i] = -1;
        lowestReach[i] = -1;
    }

    // dfs for each node
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, -1, discovery, lowestReach, visited, adj, artiPoint, timer);
        }
    }

    // print artiPoint
    cout << "Articulation Point are as Follows : ";
    for (int i = 0; i < n; i++)
    {
        if (artiPoint[i] != 0)
            cout << i << " ";
    }
    return 0;
}