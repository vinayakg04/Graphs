void BFS(map<int, vector<int>>& adj, int V, int start) {
    vector<int> visited(V, 0);
    queue<int> que;

    que.push(start);
    //Mark a node visited as soon as it's pushed into queue
    visited[start] = 1;
    while(!que.empty()) {
        int curr = que.front();
        cout << curr << " ";
        que.pop();
        for(auto i:adj[curr]) {
            if(visited[i] == 0) {
                que.push(i);
                //Mark a node visited as soon as it's pushed into queue
                visited[i] = 1;
            }
        }
    }
}
