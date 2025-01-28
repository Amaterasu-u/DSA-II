#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> par; // DSU parent map
unordered_map<int, vector<int>> graph; // Adjacency list for the graph
int totalWeight = 0;
vector<vector<pair<int, pair<int, int>>>> allMSTs; // To store all possible MSTs

void make_set(int x) {
    par[x] = x;
}

int find(int x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

int union_(int a, int b) {
    int pa = find(a), pb = find(b);
    if (pa == pb) return 0;
    graph[a].push_back(b);
    graph[b].push_back(a);
    par[pa] = pb;
    return 1;
}

// Function to reset DSU for a new MST check
void resetDSU(const vector<int> &nodes) {
    for (int node : nodes) {
        make_set(node);
        graph[node].clear();
    }
}

// Function to check if a subset of edges forms a valid MST
bool isValidMST(vector<pair<int, pair<int, int>>> &edges, int n, const vector<int> &nodes) {
    resetDSU(nodes);
    int mstWeight = 0, edgeCount = 0;

    for (auto edge : edges) {
        int w = edge.first, a = edge.second.first, b = edge.second.second;
        if (union_(a, b)) {
            mstWeight += w;
            edgeCount++;
        }
    }

    // MST is valid if it connects all vertices and matches the total weight
    return (edgeCount == n - 1 && mstWeight == totalWeight);
}

// Backtracking to find all MSTs
void findAllMSTs(vector<pair<int, pair<int, int>>> &edges, int n, int idx, vector<pair<int, pair<int, int>>> &currentMST, const vector<int> &nodes) {
    if (currentMST.size() == n - 1) {
        if (isValidMST(currentMST, n, nodes)) {
            allMSTs.push_back(currentMST);
        }
        return;
    }

    for (int i = idx; i < edges.size(); i++) {
        currentMST.push_back(edges[i]);
        findAllMSTs(edges, n, i + 1, currentMST, nodes);
        currentMST.pop_back();
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    vector<pair<int, pair<int, int>>> edges;
    vector<int> nodes;

    for (int i = 0; i < e; i++) {
        int w, a, b;
        cin >> w >> a >> b;
        edges.push_back({w, {a, b}});
        if (find(nodes.begin(), nodes.end(), a) == nodes.end()) nodes.push_back(a);
        if (find(nodes.begin(), nodes.end(), b) == nodes.end()) nodes.push_back(b);
    }
    sort(edges.begin(), edges.end());

    // Initialize DSU
    resetDSU(nodes);

    vector<pair<int, pair<int, int>>> mstEdges;

    // Kruskal's algorithm to find one MST
    for (auto edge : edges) {
        int w = edge.first, a = edge.second.first, b = edge.second.second;
        if (union_(a, b)) {
            mstEdges.push_back(edge);
            totalWeight += w;
        }
    }

    // Backtracking to find all MSTs with the same weight
    vector<pair<int, pair<int, int>>> currentMST;
    findAllMSTs(edges, n, 0, currentMST, nodes);

    // Output results
    cout << "Total Cost of MST: " << totalWeight << endl;
    cout << "All Possible MSTs:" << endl;

    for (auto &mst : allMSTs) {
        for (auto edge : mst) {
            cout << "(" << edge.second.first << ", " << edge.second.second << ", " << edge.first << ") ";
        }
        cout << endl;
    }

}
/*
4 5
1 10 20
1 10 30
1 20 30 
1 20 40 
1 30 40
*/
