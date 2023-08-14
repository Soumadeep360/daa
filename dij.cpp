#include <bits/stdc++.h>
using namespace std;

void shortestPath(int n, int m, vector<vector<int>> &edges)
{

    vector<pair<int, int>> adj[n + 1];
    for (auto it : edges)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n + 1, 1e9), parent(n + 1);
    for (int i = 1; i <= n; i++)
        parent[i] = i;

    dist[1] = 0;

    pq.push({0, 1});
    while (!pq.empty())
    {

        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int dis = it.first;

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edW = it.second;

            if (dis + edW < dist[adjNode])
            {
                dist[adjNode] = dis + edW;
                pq.push({dis + edW, adjNode});

                parent[adjNode] = node;
            }
        }
    }

    vector<int> path;

    for (int i = 1; i <= n; i++)
    {

        int node = i;

        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);

        reverse(path.begin(), path.end());
        cout << "Node " << i << " distance is: " << dist[i] << endl;
        cout << "path is : ";
        for (auto it : path)
        {
            cout << it << " ";
        }
        cout << endl;
        path.clear();
    }
}

int main()
{

    int V = 5, E = 6;
    vector<vector<int>> edges = {{1, 2, 2}, {2, 5, 5}, {2, 3, 4}, {1, 4, 1}, {4, 3, 3}, {3, 5, 1}};

    shortestPath(V, E, edges);

    return 0;
}