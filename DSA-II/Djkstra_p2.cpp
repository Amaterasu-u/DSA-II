#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<pair<int, int>>> &adj, int src, int dst, int k) {
    vector<int> dist(n, INT_MAX);
    queue<tuple<int, int, int>> pq; // {cost, node, stops}
    pq.push(make_tuple(0, src, 0));
    dist[src] = 0;

    while (!pq.empty()) {
        int cost, u, stops;
        tie(cost, u, stops) = pq.front();
        pq.pop();

        if (stops > k) {
            continue;
        }

        for (auto &edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;

            if (cost + w < dist[v]) {
                dist[v] = cost + w;
                pq.push({dist[v], v, stops + 1});
            }
        }
    }

    if (dist[dst] == INT_MAX) {
        return -1;
    } else {
        return dist[dst];
    }
}

int main() {
    int n, edge;
    cin >> n >> edge;
    
    vector<vector<pair<int, int>>> adj(n); // Adjacency list

    for (int i = 0; i < edge; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w)); // Build adjacency list directly
    }

    int src, dst, k;
    cin >> src >> dst >> k;

    int result = findCheapestPrice(n, adj, src, dst, k);
    cout << result << endl;

}
