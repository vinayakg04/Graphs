class Solution{
public:
int courseSchedule(vector<vector<int>> prerequisites,int numCourses){
int V = numCourses;
        int count = 0;
        vector<int> indegree(V, 0);
        unordered_map<int, vector<int>> adj;

        // Build the adjacency list
        for (auto &prerequisite : prerequisites) {
            adj[prerequisite[1]].push_back(prerequisite[0]);
        }

        // Compute in-degrees of all nodes
        for (int u = 0; u < V; u++) {
            for (auto &v : adj[u]) {
                indegree[v]++;
            }
        }

        // Initialize queue and result vector
        vector<int> result;
        queue<int> q;
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                result.push_back(i);
                count++;
                q.push(i);
            }
        }

        // BFS traversal
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int &v : adj[u]) {
                indegree[v]--;
                if (indegree[v] == 0) {
                    q.push(v);
                    result.push_back(v);
                    count++;
                }
            }
        }

        // Check if a valid ordering exists
        if (count < numCourses) {
            return {};
        }

        return result;
    }
};
