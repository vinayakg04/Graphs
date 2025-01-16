class Solution {
public:
      bool isValid(int x, int y, int m, int n, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        return (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && visited[x][y] == 0);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();    // Number of rows
        int m = grid[0].size(); // Number of columns

        int cnt = 0;

        queue<pair<int, int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));

        // Add all boundary cells that are 1 to the queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) { // Boundary check
                    if (grid[i][j] == 1) {
                        q.push({i, j});
                        visited[i][j] = 1;
                    }
                }
            }
        }

        // Directions for movement (down, up, right, left)
        int ax[] = {1, -1, 0, 0};
        int ay[] = {0, 0, 1, -1};

        // BFS to mark all reachable cells from boundary
        while (!q.empty()) {
            auto p = q.front();
            q.pop();

            int x1 = p.first;
            int y1 = p.second;

            for (int i = 0; i < 4; i++) {
                int x = ax[i] + x1;
                int y = ay[i] + y1;

                if (isValid(x, y, n, m, grid, visited)) {
                    q.push({x, y});
                    visited[x][y] = 1;
                }
            }
        }

        // Count the number of unvisited land cells
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    cnt++;
                }
            }
        }

        return cnt;
    }


};
