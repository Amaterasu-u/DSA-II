#include <bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>> &heights) {
    int m = heights.size(), n = heights[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    /*
    It stores {effort, {row, col}}, meaning:
effort = max height difference so far
{row, col} = current position
    */
    dist[0][0] = 0;
    pq.push({0, {0, 0}}); // {effort, {row, col}}

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!pq.empty()) {
        int effort = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if (x == m - 1 && y == n - 1) {
            return effort; // Reached the end
        }

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                int newEffort = max(effort, abs(heights[nx][ny] - heights[x][y]));
                if (newEffort < dist[nx][ny]) {
                    dist[nx][ny] = newEffort;
                    pq.push({newEffort, {nx, ny}});
                }
            }
        }
    }

    return 0; // Should never reach here
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<vector<int>> heights(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> heights[i][j];
        }
    }

    cout << minimumEffortPath(heights) << endl;
    return 0;
}
