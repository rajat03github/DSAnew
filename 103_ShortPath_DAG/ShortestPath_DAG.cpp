#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    // adjlist
    unordered_map<int, list<pair<int, int>>> adjlist;

    void addEdge(int u, int v, int weight)
    {
        // pair<int, int> p = make_pair(v, weight);
        adjlist[u].push_back(make_pair(v, weight));
    }

    void printAdj()
    {
        for (auto i : adjlist)
        {
            cout << i.first << " -> ";
            for (auto j : i.second)
            {
                cout << "{" << j.first << ", " << j.second << "}, ";
            }
            cout << endl;
        }
    }

    void dfs(int node, unordered_map<int, bool> &visited, stack<int> &topoSorted)
    {
        visited[node] = true;

        for (auto neighbr : adjlist[node])
        {
            if (!visited[neighbr.first])
            {
                dfs(neighbr.first, visited, topoSorted);
            }
        }
        topoSorted.push(node);
    }

    void getShortestPath(int source, vector<int> &distance, stack<int> &topoSort)
    {
        // distance of source is 0
        distance[source] = 0;

        while (!topoSort.empty())
        {
            int top = topoSort.top();
            topoSort.pop();

            if (distance[top] != INT_MAX) // agr distance inf nahi h tabhi processing hogi !
            {
                for (auto neighbr : adjlist[top])
                {
                    if (distance[top] + neighbr.second < distance[neighbr.first])
                    {
                        distance[neighbr.first] = distance[top] + neighbr.second;
                    }
                }
            }
        }
    }
};

int main()
{
    Graph g;
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 3, 6);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
    g.printAdj();

    int nodes = 6; // total nodes

    // requirements
    unordered_map<int, bool> visited;
    stack<int> s;

    // topological Sort
    for (int i = 0; i < nodes; i++)
    {
        if (!visited[i])
        {
            g.dfs(i, visited, s);
        }
    }

    int src = 1;
    vector<int> distance(nodes); // vector of nodes size

    for (int i = 0; i < nodes; i++)
        distance[i] = INT_MAX; // storing infinity to all indexes

    g.getShortestPath(src, distance, s);

    cout << "Answer is " << endl;

    // printing distance array
    for (int i = 0; i < distance.size(); i++)
        cout << distance[i] << " ";

    cout << endl;

    return 0;
}