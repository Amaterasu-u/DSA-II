#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    map<string, vector<pair<string, int>>> g; // Graph with city names as keys

    for (int i = 0; i < e; i++) {
        string u, v;
        int w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w}); 
    }

    // Data structures to keep track of MST
    map<string, int> key;         // Key values (weights)
    map<string, string> par;      // Parent in MST
    map<string, bool> mst;        // Whether the city is in the MST

   
    for (auto &it : g) {
        key[it.first] = INT_MAX;
        par[it.first] = "";
        mst[it.first] = false;
    }

    // Priority queue: {weight, city}
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    
    string start = g.begin()->first; // Take the first city in the map
    key[start] = 0;
    par[start] = "";
    pq.push({0, start});

    while (!pq.empty()) {
        string tmp = pq.top().second; // Current city
        pq.pop();

      //  if (mst[tmp]) continue; // If already in MST, skip
        mst[tmp] = true;

        // Explore neighbors
        for (auto it : g[tmp]) {
            string vertex = it.first; // Neighboring city
            int weight = it.second;   // Edge weight

            if (!mst[vertex] && weight < key[vertex]) {
                key[vertex] = weight;
                par[vertex] = tmp;
                pq.push({key[vertex], vertex});
            }
        }
    }

    
    int total_cost = 0;
    for (auto &it : key) {
        if (par[it.first] != "") {
            cout << par[it.first] << " - " << it.first << " : " << it.second << endl;
            total_cost += it.second;
        }
    }

    cout << "Total Cost of MST: " << total_cost << endl;

    return 0;
}
