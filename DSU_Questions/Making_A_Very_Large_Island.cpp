class Solution {
public:
    vector<vector<int>> directions = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    int DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited, int id, int n) {
        if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j]) {
            return 0;
        }

        grid[i][j] = id;
        visited[i][j] = true;
        int size = 1;

        for (auto& dir : directions) {
            int x = i + dir[0];
            int y = j + dir[1];
            size += DFS(grid, x, y, visited, id, n);
        }

        return size;
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        unordered_map<int, int> mp;  // unique_id -> size
        int id = 2;
        int maxArea = 0;

        // First DFS pass to mark islands with unique IDs and compute their sizes
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    int size = DFS(grid, i, j, visited, id, n);
                    maxArea = max(maxArea, size);
                    mp[id] = size;
                    id++;
                }
            }
        }

        // Second pass: try to convert a zero into one and check max island size
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> uniqueIds;
                    int overallSize = 1; // Start with 1 (converting this zero)

                    for (auto& dir : directions) {
                        int x = i + dir[0];
                        int y = j + dir[1];
                        if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] != 0) {
                            uniqueIds.insert(grid[x][y]);
                        }
                    }

                    for (auto& islandId : uniqueIds) {
                        overallSize += mp[islandId];
                    }

                    maxArea = max(maxArea, overallSize);
                }
            }
        }

        return maxArea;
    }
};
