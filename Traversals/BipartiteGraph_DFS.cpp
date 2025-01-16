class Solution {
public:
    bool DFS(vector<vector<int>> &graph,int u,vector<int>& color,int currColor){
         color[u] = currColor;

        for (int &v : graph[u]) {
            if (color[v] == color[u]) {
                return false; // Cannot be bipartite
            }
            if (color[v] == -1) {
                if (!DFS(graph, v, color, 1 - currColor)) {
                    return false;
                }
            }
        }

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        vector<int> color(V, -1); // -1: uncolored, 0 and 1: two colors

        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!DFS(graph, i, color, 0)) { // Start coloring with 0
                    return false;
                }
            }
        }

        return true;
    }
};
