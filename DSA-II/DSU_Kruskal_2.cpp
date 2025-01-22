#include<bits/stdc++.h>

using namespace std;

int par[1000],ans=0 , count=0;
vector<int> graph[1000];

void make_set(int x)
{
    par[x]=x;
}

int fr(int x)
{
    if(x==par[x]) return x;
    return par[x]=fr(par[x]);
}

int union_(int a,int b)
{
    int pa=fr(a),pb=fr(b);
    if(pa==pb) return 0;
    graph[a].push_back(b);
    graph[b].push_back(a);
    par[pa]=pb;
    // if(rank(pa) < rank(pb)) par[pa]=pb;
    // else par[pb]=pa; RANK BY HEIGHT
    return 1;
}

int rank(int x) {
    int height = 0;
    while (par[x] != x) {
        x = par[x];
        height++;
    }
    return height;
}


int main()
{
    int n,e; cin >> n >> e;

    for(int i=1;i<=n;i++) make_set(i);

    vector<pair<int,pair<int,int>>> edges;
    for(int i=0;i<e;i++)
    {
        int a,b,w; cin >> w >> a >> b;
        edges.push_back({w,{a,b}});
    }
    sort(edges.begin(),edges.end());

    cout<<"Verifying sorted edges: "<<endl;

    for(auto v:edges)
    {
        cout << v.first << " " << v.second.first << " " << v.second.second;
        cout << endl;
    }

    cout<<endl;
    
    for(auto v:edges)
    {

        int ret=union_(v.second.first , v.second.second);
        if(ret==1) {
        ans+=v.first;
       //count++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout << i << " has edges with: ";
        for(auto x:graph[i]) cout << x << " ";
        cout << endl;
    }

    cout << endl << ans << endl;

    return 0;
}
