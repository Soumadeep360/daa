#include <bits/stdc++.h>
using namespace std;


class DisjointSet {
    vector<int>  parent, size;
public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }


    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    vector<pair<int,pair<int,int>>> spanningTree(int V, vector<pair<int, pair<int,int>>>edges)
    {
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        vector<pair<int,pair<int,int>>> mst;
        for (auto it : edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUPar(u) != ds.findUPar(v)) {
                mst.push_back({wt,{u,v}});
                ds.unionBySize(u, v);
            }
        }

        return mst;
    }
};

int main() {

     int V, E, start;
  cout << "Enter the number of vertices and edges of the graph:\n";
  cin >> V >> E;
vector<pair<int, pair<int,int>>>edges;
  cout << "Enter the adjacency list with edge weights:\n";
  for (int i = 0; i < E; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    edges.push_back({w, {u, v}});
  }

    Solution obj;
    int sumWt=0;
    vector<pair<int,pair<int,int>>> mst = obj.spanningTree(V, edges);
    for(auto it:mst)
    {
        sumWt+=it.first;
    cout << "the edges are: " <<it.second.first<<","<<it.second.second<<"-->"<<it.first << endl;
    }
    cout<<"the sum of weight "<<sumWt<<endl;
return 0;
}