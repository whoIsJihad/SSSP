#include <bits/stdc++.h>
using namespace std;
void dfs(int node,vector<vector<pair<int,int>>> &adj, vector<int> &dist, vector<bool> &vis,vector<int> &parent)
{
    vis[node] = true;
    for (auto it : adj[node])
    {
        if (!vis[it.first])
        {
            dist[it.first] =it.second+dist[node];
            parent[it.first]=node;
            dfs(it.first, adj, dist, vis,parent);
        }
    }
}

int main()
{

    int m, n;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    vector<vector<int>>edges;
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
        edges.push_back({u,v,wt});
    }
    vector<int> dist(n, INT_MAX);
    vector<bool> vis(n, false);
    vector<int> parent(n,-1);
    dist[0] = 0;
    dfs(0, adj, dist, vis,parent);

    for (int i = 0; i < n; i++)
    {
        cout << dist[i] << " ";
    }
    cout << endl;
    int start=-1;
    for(auto edge:edges)
    {
        int u=edge[0];
        int v=edge[1];
        int wt=edge[2];
        if(dist[u]+wt<dist[v])
        {
            cout<<"Negative cycle found"<<endl;
            parent[v]=u;
            start=v;
            break;
        }
    }
    if(start==-1)
    {
        cout<<"No negative cycle found"<<endl;
    }
    else
    {
        cout<<"Parent array:: "<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<parent[i]<<" ";
        }
        cout<<endl;

    cout<<"Negative cycle:: "<<endl;
    int mainStart=start;
    do {
        cout<<start<<" ";
        start=parent[start];
    } while (start!=mainStart);
    }

}

/*
5 5 
0 1 3
1 3 -4
3 2 7
2 1 3
2 4 8

*/