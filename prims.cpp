#include <bits/stdc++.h>
using namespace std;

// Function to find sum of weights of edges of the Minimum Spanning Tree.
int MST(int V, vector<vector<int>> adj[], int start)
{
  priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

  vector<int> vis(V, 0);
  vector<pair<int, int>> edges;

  pq.push({0, -1, start});
  int sum = 0;
  while (!pq.empty())
  {
    auto it = pq.top();
    pq.pop();

    int node = it[2];
    int parent = it[1];
    int wt = it[0];

    if (vis[node])
      continue;

    vis[node] = 1;
    sum += wt;

    edges.push_back({parent, node});

    for (auto x : adj[node])
    {
      if (!vis[x[0]])
      {
        pq.push({x[1], node, x[0]});//{wt,parent,node}
      }
    }
  }
  for (auto x : edges)
  {
    if (x.first == -1)
    {
      continue;
    }
    cout << x.first << '-' << x.second << endl;
  }
  return sum;
}

int main()
{
  int V, E, start;
  cout << "Enter the number of vertices and edges of the graph:\n";
  cin >> V >> E;
  vector<vector<int>> adj[V];

  cout << "Enter the adjacency list with edge weights:\n";
  for (int i = 0; i < E; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
  }
  cout << "Enter the start node: ";
  cin >> start;

  cout << MST(V, adj, start) << "\n";

  return 0;
}