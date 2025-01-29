#include <bits/stdc++.h>
using namespace std;

int minimumEffortPath(vector<vector<int>>& heights) {
    int m = heights.size(), n = heights[0].size();
    vector<vector<int>> dist(m, vector<int>(n, INT_MAX));  // Stores the minimum effort to reach each cell
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    dist[0][0] = 0;  // Starting point has 0 effort
    pq.push({0, {0, 0}});  // {effort, {row, col}}

    int dx[] = {-1, 1, 0, 0};  // Directions for moving up, down, left, right
    int dy[] = {0, 0, -1, 1};

    while (!pq.empty()) {
        int effort = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        // If we reach the bottom-right corner, return the effort
        if (x == m - 1 && y == n - 1) {
            return effort;
        }

        // Explore the 4 adjacent cells
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];  // Next row
            int ny = y + dy[i];  // Next column

            // Check if the next position is within bounds
            if (nx >= 0 && ny >= 0 && nx < m && ny < n && heights[nx][ny]==0) {
                    dist[nx][ny] = dist[x][y]+1;
                    pq.push({dist[nx][ny], {nx, ny}});
                }
            }
        }
        return -1;  // If there's no path to the bottom-right corner
    }




int main() {
    int m, n;
    cin >> m >> n;  // Input the grid dimensions
    vector<vector<int>> heights(m, vector<int>(n));

    // Input the grid values
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> heights[i][j];
        }
    }

    // Output the minimum effort path
    cout << minimumEffortPath(heights) << endl;
    return 0;
}
