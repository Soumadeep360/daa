#include <bits/stdc++.h>
using namespace std;

void shortestPath(int V, vector<pair<int,int>>adj[])
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(V, 1e9), parent(V);
    for (int i = 0; i < V; i++)
        parent[i] = i;

    dist[0] = 0;

    pq.push({0, 0}); //{dis,node}
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

    for (int i = 0; i < V; i++)
    {

        int node = i;

        while (parent[node] != node)
        {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(0);

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

     int V, E, start;
  cout << "Enter the number of vertices and edges of the graph:\n";
  cin >> V >> E;
  vector<pair<int,int>> adj[V];

  cout << "Enter the adjacency list with edge weights:\n";
  for (int i = 0; i < E; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }

    shortestPath(V, adj);

    return 0;
}
