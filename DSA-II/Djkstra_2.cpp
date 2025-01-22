#include <bits/stdc++.h>
using namespace std;

void dijkstra(const unordered_map<int, vector<pair<int, int>>> &adj, unordered_map<int, int> &dist, unordered_map<int, int> &par, int src)
{
    unordered_map<int, bool> visited;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        // Skip already processed nodes
        if (visited[u]) continue;
        visited[u] = true;

        for (const auto &edge : adj.at(u)) // SYNTAX DIFFERENT
        {
            int v = edge.first;
            int w = edge.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                par[v] = u;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    int node, edge;
    cin >> node >> edge;


    unordered_map<int, vector<pair<int, int>>> adj;
    unordered_map<int, int> dist, par;

    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // Directed graph
    }

    // Initialize distances and parents
    for (const auto &entry : adj)
    {
        dist[entry.first] = INT_MAX;
        par[entry.first] = -1;
    }

    int src = 1; // Default source node
    dist[src] = 0;
    dijkstra(adj, dist, par, src);

    cout << "Node -> Distance from Source\n";
    for (const auto &entry : adj)
    {
        int node = entry.first;
        if (dist[node] == INT_MAX)
        {
            cout << node << " -> -1\n";
        }
        else
        {
            cout << node << " -> " << dist[node] << '\n';
        }
    }

    cout << "\nShortest Paths from Source Node " << src << ":\n";
    for (const auto &entry : adj)
    {
        int node = entry.first;
        if (dist[node] == INT_MAX)
        {
            cout << node << ": No path\n";
        }
        else
        {
            cout << node << ": ";
            vector<int> path;
            int curr = node;
            while (curr != -1)
            {
                path.push_back(curr);
                curr = par[curr];
            }
            reverse(path.begin(), path.end());
            for (int n : path)
            {
                cout << n << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}
