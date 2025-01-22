#include <bits/stdc++.h>
using namespace std;

void bellmanFord(int node, int edge, const vector<tuple<int, int, int>> &edges, unordered_map<int, int> &dist, unordered_map<int, int> &par, int src = 1)
{
    // Initialize distances and parents
    dist.clear();
    par.clear();

    // Set initial values for distance and parent
    for (const auto &e : edges)
    {
        int u, v, w;
        tie(u, v, w) = e;
        dist[u] = INT_MAX;
        dist[v] = INT_MAX;
        par[u] = -1;
        par[v] = -1;
    }

    dist[src] = 0;

    // Relax edges (node - 1) times
    for (int i = 1; i <= node - 1; i++)
    {
        bool updated = false;

        for (const auto &e : edges)
        {
            int u, v, w;
            tie(u, v, w) = e;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                par[v] = u;
                updated = true;
            }
        }

        // If no update occurs in an iteration, break early
        if (!updated)
        {
            break;
        }
    }

    // Check for negative weight cycles
    for (const auto &e : edges)
    {
        int u, v, w;
        tie(u, v, w) = e;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v])
        {
            cout << "Negative weight cycle detected!" << endl;
            return;
        }
    }

    cout << "No negative weight cycle detected." << endl;
}

int main()
{
    int node, edge;
    cin >> node >> edge;

    vector<tuple<int, int, int>> edges;

    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w}); // Directed graph
    }

    unordered_map<int, int> distance, parent;
    int src = 2; // Default source node
    bellmanFord(node, edge, edges, distance, parent, src);

    cout << "Node -> Distance from Source\n";
    for (const auto &entry : distance)
    {
        cout << entry.first << " -> ";
        if (entry.second == INT_MAX)
        {
            cout << "Infinity";
        }
        else
        {
            cout << entry.second;
        }
        cout << '\n';
    }

    cout << "\nShortest Paths from Source Node " << src << ":\n";
    for (const auto &entry : distance)
    {
        int node = entry.first;
        if (entry.second == INT_MAX)
        {
            cout << node << ": No path\n";
        }
        else
        {
            vector<int> path;
            int curr = node;
            while (curr != -1)
            {
                path.push_back(curr);
                curr = parent[curr];
            }
            reverse(path.begin(), path.end());
            cout << node << ": ";
            for (int p : path)
            {
                cout << p << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}
