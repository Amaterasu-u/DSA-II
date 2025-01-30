#include <bits/stdc++.h>
using namespace std;

int shortestPath(vector<vector<int>>& grid, int k) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<vector<int>>> visited(m, vector<vector<int>>(n, vector<int>(k + 1, 0)));
    
/*
A normal visited[x][y] (2D array) isn't enough because we can reach (x, y) with different numbers of obstacles left.
We need visited[x][y][remaining_k] to track multiple states.
Example: If you reach (2,3) with k=5 remaining, it's not the same as reaching (2,3) with k=1.
*/


    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<>> pq;
    
    // {steps, remaining_k, row, col}
    pq.push(make_tuple(0, k, 0, 0));
    visited[0][0][k] = 1;

    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};

    while (!pq.empty()) {
        tuple<int, int, int, int> t = pq.top();
        pq.pop();

        int steps = get<0>(t);
        int remaining_k = get<1>(t);
        int x = get<2>(t);
        int y = get<3>(t);

        if (x == m - 1 && y == n - 1) return steps; // Reached end

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                int new_k = remaining_k - grid[nx][ny];

                if (new_k >= 0 && !visited[nx][ny][new_k]) {
                    visited[nx][ny][new_k] = 1;
                    pq.push(make_tuple(steps + 1, new_k, nx, ny));
                }
            }
        }
    }

    return -1; // No valid path found
}

int main() {
    int m, n, k;
    cin >> m >> n >> k;
    vector<vector<int>> grid(m, vector<int>(n));

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }

    cout << shortestPath(grid, k) << endl;
    return 0;
}
