#include<bits/stdc++.h>

using namespace std;

void djk(unordered_map<int,vector<pair<int,int>>> &adj , unordered_map<int,int> &dist , unordered_map<int,int> &par , int src=1){
    priority_queue<pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
    dist[src]=0;
    unordered_map<int , bool> visited;
    pq.push({0,src});
    while(!pq.empty()){
        int u = pq.top().second;
        int w =pq.top().first;
        pq.pop();

        if(visited[u]) continue;
        visited[u]=true;

        for(auto &e : adj.at(u)){
            int v = e.first;
            int w = e.second;
            if(dist[u]+w < dist[v]){
                dist[v]=dist[u]+w;
                par[v]=u;
                pq.push({dist[v],v});
                }
        }
    }
}





int main(){

    int node,edge;
    cin>>node>>edge;
    unordered_map<int,vector<pair<int,int>>> adj;
    for(int i=0;i<edge;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});

    }
    unordered_map<int,int>dist;
    unordered_map<int,int>par;

for(auto &edges:adj){
dist[edges.first] = INT_MAX;
par[edges.first] = -1;
}

djk(adj , dist , par);

}