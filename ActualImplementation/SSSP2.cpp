#include<bits/stdc++.h>
#define iPair pair<long long int, long long int>
using namespace std;

//takes input adjacentcy list and returns the dist vector from src

vector<long long int> SSSP_dijistra(vector<vector<iPair>> graph, long long int src)
{
    long long int n = graph.size();

    vector<long long int> dist(n, LLONG_MAX);

    priority_queue<iPair, vector<iPair>, greater<iPair>> pq;
    dist[src] = 0;
    // pushing the src in the heap
    pq.push({0, src});

    while (!pq.empty())
    {
        auto mini = pq.top();
        pq.pop();

        long long int minNode = mini.second;

        for (auto edgeFromMini : graph[minNode])
        {
            long long int u = minNode;
            long long int v = edgeFromMini.first;
            long long int w = edgeFromMini.second;

            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main(){
    long long int m,n,k;
    cin>>n>>m>>k;

    vector<vector<iPair>> graph(n);
    for(long long int i=0;i<m;i++){
        long long int u,v,w;
        cin>>u>>v>>w;
        u--;
        v--;
        graph[v].push_back({u,w});
        graph[u].push_back({v,w});
    }
    //contains cost of reaching ith city from 1
    vector<long long int> dist=SSSP_dijistra(graph,0);

    //train routes from 1 to ith city can be closed if shortest distance by train is >= 
    //shortest distance by bus 
    long long int ans=0;

    for(long long int i=0;i<k;i++){
        long long int u,v;
        cin>>u>>v;
        u--;
        if(dist[u]<=v) ans++;
    }
    cout<<ans;
}