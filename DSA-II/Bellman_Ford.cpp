#include <bits/stdc++.h>
using namespace std;

void bellmanFord(int node, int edge, const vector<tuple<int, int, int>> &edges, vector<int> &dist, vector<int> &par, int src = 1)
{
    dist.assign(node + 1, INT_MAX);
    par.assign(node + 1, -1);

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
            break; /*
            so basically if lets say I could make a change for
             3 iterations and at the 4th iteration if no change occurs it will break
            */
        }
    }

    // Check for negative weight cycles
    for (const auto &e : edges) /*
    n-1 iterations er por jodi still update kora possible hoy that INDICATES A NEGATIVE CYCLE
    */
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
        // edges.push_back({v, u, w});
    }

    vector<int> distance, parent;
    int src = 2; // Default source node
    bellmanFord(node, edge, edges, distance, parent, src);

    cout << "Node -> Distance from Source\n";
    for (int i = 1; i <= node; i++)
    {
        cout << i << " -> ";
        if (distance[i] == INT_MAX)
        {
            cout << "Infinity";
        }
        else
        {
            cout << distance[i];
        }
        cout << '\n';
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
            vector<int> path;
            int curr = i;
            while (curr != -1)
            {
                path.push_back(curr);
                curr = parent[curr];
            }
            reverse(path.begin(), path.end());
            cout << i << ": ";
            for (int p : path)
            {
                cout << p << " ";
            }
            cout << '\n';
        }
    }

    return 0;
}
/*
5 8
1 2 6
1 3 7
2 3 8
2 4 5
2 5 -4
3 4 -3
4 5 9
5 2 7



5 6
1 2 5
2 3 -1
4 2 -3
2 5 3
3 4 -2
3 5 2

*/ 