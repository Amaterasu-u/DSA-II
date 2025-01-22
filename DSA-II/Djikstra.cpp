#include <bits/stdc++.h>
using namespace std;

void dijkstra(const vector<vector<pair<int, int>>> &adj, vector<int> &dist, vector<int> &par, int src = 1)
{
    int n = adj.size();
    dist.assign(n, INT_MAX);
    par.assign(n, -1);

    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src}); // {distance, node}

    while (!pq.empty())
    {
        int u = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (d > dist[u])
            continue;

        for (const auto &edge : adj[u])
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
    
     vector<vector<pair<int, int>>> adj(node + 1);

    for (int i = 0; i < edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back({v, w}); // Directed graph
    }

    vector<int> distance, parent;
    int src = 1; // Default source node
    dijkstra(adj, distance, parent, src);

    cout << "Node -> Distance from Source\n";
    for (int i = 1; i <= node; i++)
    {
        cout << i << " -> " << (distance[i] == INT_MAX ? -1 : distance[i]) << '\n';
    }

    cout << "\nShortest Paths from Source Node " << src << ":\n";
    for (int i = 1; i <= node; i++)
    {
        if (distance[i] == INT_MAX)
        {
            cout << i << ": No path\n";
        }
        else
        {
            cout << i << ": ";
            vector<int> path;
            int curr = i;
            while (curr != -1)
            {
                path.push_back(curr);
                curr = parent[curr];
            }
            reverse(path.begin(), path.end());
            for (int node : path)
            {
                cout << node << " ";
            }
            cout << "\n";
        }
    }

    return 0;
}

/*
Input:
6 10
1 2 50
1 4 10
2 4 15
1 3 45
2 3 10
4 5 15
6 5 3
5 3 35
3 5 30
5 2 20
*/