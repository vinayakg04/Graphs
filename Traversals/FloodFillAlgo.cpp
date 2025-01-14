
Class Solution{


// Helper function to check if the cell is valid for coloring
    bool isValid(int x, int y, int m, int n, vector<vector<int>>& image, int originalColor) {
        return (x >= 0 && x < m && y >= 0 && y < n && image[x][y] == originalColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();    // Number of rows
        int n = image[0].size(); // Number of columns

        int originalColor = image[sr][sc];

        // If the starting pixel is already the target color, no changes are needed
        if (originalColor == color) {
            return image;
        }

        // Queue for BFS
        queue<pair<int, int>> q;
        q.push({sr, sc});

        // Directions for moving up, down, left, and right
        int ax[] = {-1, 1, 0, 0};
        int ay[] = {0, 0, -1, 1};

        // Perform BFS
        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            // Update the current cell to the new color
            image[x][y] = color;

            // Check all 4 neighbors
            for (int i = 0; i < 4; i++) {
                int newX = x + ax[i];
                int newY = y + ay[i];

                // If the neighbor is valid, add it to the queue
                if (isValid(newX, newY, m, n, image, originalColor)) {
                    q.push({newX, newY});
                }
            }
        }

        return image;
    }
}
