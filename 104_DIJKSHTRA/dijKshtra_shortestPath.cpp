#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{

    // create adjlist ~ pair because weighted
    unordered_map<int, list<pair<int, int>>> adjlist;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        // undirected
        adjlist[u].push_back(make_pair(v, w));
        adjlist[v].push_back(make_pair(u, w));
    }

    // create distance array
    vector<int> distance(vertices);
    for (int i = 0; i < distance.size(); i++)
        distance[i] = INT_MAX; // initialize with INT MAX

    // create set
    set<pair<int, int>> set;

    // processing now
    distance[source] = 0;
    set.insert(make_pair(0, source)); // {distance , node}

    while (!set.empty())
    {
        // fetch top record
        auto top = *(set.begin());

        int nodeDistance = top.first;
        int topNode = top.second;

        // remove set record now
        set.erase(set.begin());

        // traverse on neighbrs from adjlist
        for (auto neighbr : adjlist[topNode])
        {
            if (nodeDistance + neighbr.second < distance[neighbr.first])
            {
                // pahle se agar padha hai woh find karo
                auto record = set.find(make_pair(distance[neighbr.first], neighbr.first));

                // if record found , then erase it
                if (record != set.end())
                    set.erase(record);

                // update distance
                distance[neighbr.first] = nodeDistance + neighbr.second;

                // push record in set
                set.insert(make_pair(distance[neighbr.first], neighbr.first));
            }
        }
    }

    return distance;
}

/*
#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{

    // create adjlist ~ pair because weighted
    unordered_map<int, list<pair<int, int>>> adjlist;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];

        // undirected
        adjlist[u].push_back(make_pair(v, w));
        adjlist[v].push_back(make_pair(w, w));
    }

    // create distance array
    vector<int> distance(vertices, INT_MAX);
    distance[source] = 0;

    // create set
    set<pair<int, int>> st;

    // processing now

    st.insert(make_pair(0, source)); // {distance , node}

    while (!st.empty())
    {
        // fetch top record
        pair<int , int > top = *(st.begin());
         // remove set record now
        st.erase(st.begin());

        int nodeDistance = top.first;
        int topNode = top.second;



        // traverse on neighbrs from adjlist
        for (auto neighbr : adjlist[topNode])
        {
            if (nodeDistance + neighbr.second < distance[neighbr.first])
            {
                // pahle se agar padha hai woh find karo
                auto record = st.find(make_pair(distance[neighbr.first], neighbr.first));

                // if record found , then erase it
                if (record != st.end())
                    st.erase(record);

                // update distance
                distance[neighbr.first] = nodeDistance + neighbr.second;

                // push record in set
                st.insert(make_pair(distance[neighbr.first], neighbr.first));
            }
        }
    }

    return distance;
}
*/