#include <bits/stdc++.h>
using namespace std;

int totalWeight = 0;
vector<vector<pair<int, int>>> graph;
vector<vector<pair<int, pair<int, int>>>> allMSTs; // To store all possible MSTs

// Function to find all possible MSTs using Prim's algorithm with backtracking
void primAllMSTs(int n) {
    vector<bool> inMST(n + 1, false);   // To track which vertices are in the MST
    vector<int> parent(n + 1, -1);      // To store the MST
    vector<int> key(n + 1, INT_MAX);    // Key values to pick minimum weight edge
    key[1] = 0; // Start from vertex 1 (arbitrary)
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1}); // Start from vertex 1 with weight 0
    
    vector<pair<int, pair<int, int>>> currentMSTEdges; // Store edges in the current MST
    vector<vector<pair<int, pair<int, int>>>> allCurrentMSTs; // To store all MSTs explored during the search

    while (!pq.empty()) {
        int u = pq.top().second;
        int w = pq.top().first;
        pq.pop();
        
        if (inMST[u]) continue;
        
        inMST[u] = true;
        totalWeight += w;
        
        // Explore neighbors
        vector<pair<int, pair<int, int>>> addedEdges; // Store edges added in this step
        
        for (auto &neighbor : graph[u]) {
            int v = neighbor.first;
            int weight = neighbor.second;
            
            // If the edge can improve the MST, select it
            if (!inMST[v] && weight < key[v]) {
                key[v] = weight;
                parent[v] = u;
                pq.push({weight, v});
                addedEdges.push_back({weight, {u, v}});
            }
        }
        
        // After processing the edges, we explore multiple MSTs by selecting any valid edges
        if (addedEdges.size() > 1) {
            // Handle multiple edges that can form different MSTs (backtracking here)
            for (auto &edge : addedEdges) {
                vector<pair<int, pair<int, int>>> newMST = currentMSTEdges;
                newMST.push_back(edge);
                allCurrentMSTs.push_back(newMST);
            }
        } else {
            // Otherwise, we just extend the current MST
            currentMSTEdges.push_back(addedEdges[0]);
        }
    }

    // After the loop, check for all found MSTs
    if (currentMSTEdges.size() == n - 1) {
        allMSTs.push_back(currentMSTEdges);
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    graph.resize(n + 1);

    for (int i = 0; i < e; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }

    primAllMSTs(n);

    // Output the results
    cout << "All Possible MSTs:" << endl;
    for (auto &mst : allMSTs) {
        for (auto &edge : mst) {
            cout << "(" << edge.second.first << ", " << edge.second.second << ", " << edge.first << ") ";
        }
        cout << endl;
    }

    return 0;
}
