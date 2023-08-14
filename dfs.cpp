// #include <bits/stdc++.h>
// using namespace std;

// void dfs(int node, int vis[], vector<int> adj[])
// {
//     vis[node] = 1;
//     cout << node << " ";
//     for (auto it : adj[node])
//     {
//         if (!vis[it])
//             dfs(it, vis, adj);
//     }
// }

// int main()
// {
//     int V;
//     cout << "Enter the number of vertices: ";
//     cin >> V;

//     int mat[V][V];
//     cout << "Enter the adjacency matrix:" << endl;
//     for (int i = 0; i < V; i++)
//     {
//         for (int j = 0; j < V; j++)
//         {
//             cin >> mat[i][j];
//         }
//     }

//     vector<int> adj[V];
//     for (int i = 0; i < V; i++)
//     {
//         for (int j = 0; j < V; j++)
//         {
//             if (mat[i][j] == 1 && i != j)
//             {
//                 adj[i].push_back(j);
//             }
//         }
//     }

//     int startNode;
//     cout << "Enter the starting node: ";
//     cin >> startNode;

//     int vis[V] = {0};
//     cout << "The DFS traversal is: ";
//     dfs(startNode, vis, adj);
//     cout << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

vector<int>dfsOfGraph(int V,int startNode,vector<int>adj[]){
    int vis[V]={0};
    vis[startNode]=1;
    stack<int>q; //change
    q.push(startNode);
    vector<int>dfs;
    while(!q.empty())
    {
        int node=q.top();//change
        q.pop();
        dfs.push_back(node);
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push(it);
            }
        }
    }

    return dfs;
}
int main()
{
    int V;
    cout<<"enter the number of vertex"<<endl;
    cin>>V;
    int mat[V][V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            cin>>mat[i][j];
        }
    }
    vector<int>adj[V];
    for(int i=0;i<V;i++)
    {
        for(int j=0;j<V;j++)
        {
            if(mat[i][j]==1 && i!=j){
            adj[i].push_back(j);
            }
        }
    }
    int startNode;
    cout<<"enter the starting node"<<endl;
    cin>>startNode;
    vector<int>ans=dfsOfGraph(V,startNode,adj);
    cout<<"the dfs traversal is: "<<endl;
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}

// // 0 1 1 0 0 0 0
// // 0 0 0 0 0 1 1
// 0 0 0 1 1 0 0
// 0 0 1 0 0 0 0 
// 0 0 1 0 0 0 0
// 0 1 0 0 0 0 0
// 0 1 0 0 0 0 0