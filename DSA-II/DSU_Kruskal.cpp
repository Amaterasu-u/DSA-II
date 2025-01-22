#include<bits/stdc++.h>
using namespace std;

int n, e, par[1000000];
vector<int> graph[1000];

void make_set(int x) {
    par[x] = x;
}

int fR(int x) {
    if (par[x] == x) return x;
    return par[x] = fR(par[x]); // Path compression
}

bool union_(int a, int b) {
    int pa = fR(a), pb = fR(b);
    if (pa == pb) return false; // The edge forms a cycle
    par[pb] = pa; // Union the two sets
    return true;
}

int rank(int x) {
    int height = 0;
    while (par[x] != x) {
        x = par[x];
        height++;
    }
    return height;
}

int main() {
    cin >> n >> e;
    vector<int> nodes;
    vector<pair<int, pair<int, int>>> edges; // {weight, {node1, node2}}

    for (int i = 1; i <= n; i++) {
        make_set(i);
        nodes.push_back(i);
    }

    int a, b, w;    
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> w;
        edges.push_back({w, {a, b}});
    }

    sort(edges.begin(), edges.end()); // Sort edges by weight

    // Printing edges
    for (auto v : edges) {
        cout << v.first << " " << v.second.first << " " << v.second.second << endl;
    }

    int ans = 0; // Total weight of MST
    vector<pair<int, int>> mst; // To store edges of the MST

    for (auto v : edges) {
        if (union_(v.second.first, v.second.second)) {
            ans += v.first; // Add the weight of the edge to the MST
            mst.push_back({v.second.first, v.second.second}); // Store the edge in the MST
        }
    }

    cout << "Weight of MST: " << ans << endl;

    cout << "Edges in MST:" << endl;
    for (auto edge : mst) {
        cout << edge.first << " " << edge.second << endl;
    }

    // vector<bool> visited(n + 1, false);
    // for (auto rep : nodes) {
    //     int p = fR(rep);
    //     if (!visited[p]) {
    //         visited[p] = true;
    //         cout << p << endl; 
    //     }
    // }

    return 0;
}
