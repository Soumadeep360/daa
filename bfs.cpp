#include <bits/stdc++.h>
using namespace std;

vector<int>bfsOfGraph(int V,int startNode,vector<int>adj[]){
    int vis[V]={0};
    vis[startNode]=1;
    queue<int>q;
    q.push(startNode);
    vector<int>bfs;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        bfs.push_back(node);
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                vis[it]=1;
                q.push(it);
            }
        }
    }

    return bfs;
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
    vector<int>ans=bfsOfGraph(V,startNode,adj);
    cout<<"the Bfs traversal is: "<<endl;
    for(auto it:ans)
    {
        cout<<it<<" ";
    }
    cout<<endl;
}

// 0 1 1 0 0 0 0
// 0 0 0 0 0 1 1
// 0 0 0 1 1 0 0
// 0 0 1 0 0 0 0 
// 0 0 1 0 0 0 0
// 0 1 0 0 0 0 0
// 0 1 0 0 0 0 0