#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, e;
    cin >> n >> e;

    map<int, vector<pair<int, int>>> g; 
    set<int> vertices; // To store unique vertex IDs

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        vertices.insert(u); // Add unique vertices to the set
        vertices.insert(v);
    }


    map<int, int> key;     // Stores minimum weight to connect a vertex
    map<int, int> par;     // Stores parent of each vertex in the MST
    map<int, bool> mst;    // Tracks if a vertex is included in the MST

    // Initialize maps for all vertices
    for (int vertex : vertices) {
        key[vertex] = INT_MAX;
        par[vertex] = -1;
        mst[vertex] = false;
    }

    // Priority queue to select the minimum weight edge
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // Start from any vertex (e.g., the first one in the graph)
    int start = *vertices.begin();
    key[start] = 0;
    pq.push({0, start});

    while (!pq.empty()) {
        int tmp = pq.top().second;
        pq.pop();


        mst[tmp] = true;

        for (auto it : g[tmp]) {
            int vertex = it.first;
            int weight = it.second;

            if (!mst[vertex] && weight < key[vertex]) {
                key[vertex] = weight;
                par[vertex] = tmp;
                pq.push({key[vertex], vertex});
            }
        }
    }


    int totalCost = 0;
    for (auto v : vertices) {
        if (key[v] != INT_MAX) {
            totalCost += key[v];
        }
    }

    cout << "Total Cost of MST: " << totalCost << endl;

    return 0;
}
