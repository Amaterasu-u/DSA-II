#include <bits/stdc++.h>
using namespace std;

int par[1000], ans = 0, totalWeight = 0;
vector<int> graph[1000];
vector<vector<pair<int, pair<int, int>>>> allMSTs; // To store all possible MSTs

void make_set(int x) {
    par[x] = x;
}

int fr(int x) {
    if (x == par[x]) return x;
    return par[x] = fr(par[x]);
}

int union_(int a, int b) {
    int pa = fr(a), pb = fr(b);
    if (pa == pb) return 0;
    graph[a].push_back(b);
    graph[b].push_back(a);
    par[pa] = pb;
    return 1;
}

// Function to reset DSU for a new MST check
void resetDSU(int n) {
    for (int i = 1; i <= n; i++) {
        make_set(i);
        graph[i].clear();
    }
}

// Function to check if a subset of edges forms a valid MST
bool isValidMST(vector<pair<int, pair<int, int>>> &edges, int n) {
    resetDSU(n);
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

// Backtracking to find all MSTs MAIN KAHINI EKHANE!!!!!!!!!!!
void findAllMSTs(vector<pair<int, pair<int, int>>> &edges, int n, int idx, vector<pair<int, pair<int, int>>> &currentMST) {
    if (currentMST.size() == n - 1) {
        if (isValidMST(currentMST, n)) {
            allMSTs.push_back(currentMST);
        }
        return;
    }

    for (int i = idx; i < edges.size(); i++) {
        currentMST.push_back(edges[i]);
        findAllMSTs(edges, n, i + 1, currentMST);
        currentMST.pop_back();
    }
}

int main() {
    int n, e;
    cin >> n >> e;

    for (int i = 1; i <= n; i++) make_set(i);

    vector<pair<int, pair<int, int>>> edges;
    for (int i = 0; i < e; i++) {
        int a, b, w;
        cin >> w >> a >> b;
        edges.push_back({w, {a, b}});
    }
    sort(edges.begin(), edges.end());

    vector<pair<int, pair<int, int>>> mstEdges;


    for (auto edge : edges) {
        int w = edge.first, a = edge.second.first, b = edge.second.second;
        if (union_(a, b)) {
            mstEdges.push_back(edge);
            totalWeight += w;
        }
    }

    // Backtracking to find all MSTs with the same weight
    vector<pair<int, pair<int, int>>> currentMST;
    findAllMSTs(edges, n, 0, currentMST);

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