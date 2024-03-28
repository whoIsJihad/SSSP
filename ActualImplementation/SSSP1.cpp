#include<bits/stdc++.h>
using namespace std;

// Bellman Ford Algorithm
// Time Complexity: O(N*M)
// Space Complexity: O(N)
// N: Number of nodes
// M: Number of edges
vector<int> bellmanFord(int n, int src, vector<vector<int>>edges){
    vector<int>dist(n,INT_MAX);
    vector<int>parent(n,-1);

    parent[src]=-1;
    dist[src]=0;
    for(int i=0;i<n-1;i++){
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            int w=edge[2];
            if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
                parent[v]=u;
            }
        }
    }

    for(auto edge:edges){
        int u=edge[0];
        int v=edge[1];
        int w=edge[2];
        if(dist[u]!=INT_MAX && dist[u]+w<dist[v]){
            cout<<"Negative Cycle";
            return dist;
        }
    }

    // parent
    cout<<"Parent: "<<endl;

    for(int i=0;i<n;i++){
        if(parent[i]!=-1){
            cout<<i<<" "<<parent[i]<<endl;
        }
        else cout<<i<<" -1"<<endl;
    }
    return dist;
}

int main(){
    int m,n;
    cin>>n>>m;
    vector<vector<int>>edges;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;

        edges.push_back({u,v,w});
        edges.push_back({v,u,w});
    }
    cout<<"Enter Source: ";
    int src;
    cin>>src;
    src--;
    vector<int>dist=bellmanFord(n,src,edges);
    cout<<"Distance: "<<endl;

    for(int i=0;i<n;i++){
        cout<<i<<" "<<dist[i]<<endl;
    }
    return 0;

}