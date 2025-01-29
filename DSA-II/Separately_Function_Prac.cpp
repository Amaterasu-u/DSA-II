#include <bits/stdc++.h>
using namespace std;


void bf(int n,int e,vector<tuple<int,int,int>> &edges , vector<int> &dis , vector<int>& par, int src){
dis.assign(n+1,INT_MAX);
par.assign(n+1,-1);

dis[src]=0;
for(int i=1;i<=n-1;i++){
    bool updated=false;
    for(auto &edge : edges){
        int u,v,w;
        tie(u,v,w) = edge;
        if(dis[u]!=INT_MAX && dis[u]+w < dis[v]){
            dis[v]=dis[u]+w;
            par[v]=u;
            updated=true;
        }
    }
    if(!updated){}
}

}


int main() {

int n,e;
cin>>n>>e;
vector<tuple<int,int,int>> edges;
for(int i=0;i<e;i++){
    int u,v,w;
    cin>>u>>v>>w;
    edges.push_back({u,v,w});
}
vector<int> dis,par;
int src=1;
bf(n,e,edges,dis,par,src);


}
