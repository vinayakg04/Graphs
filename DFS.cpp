 void DFS(vector<bool> &visited,vector<int> &result,int u,unordered_map<int,vector<int>> &adj){
        
        if(visited[u]==true){
            return;
        }
        else{
            visited[u]=true;
            result.push_back(u);
        }
        
        for(auto &v: adj[u]){
            if(!visited[v]){
            DFS(visited,result,v,adj);
        }
        }
        
    }
    
    
    
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        // Code here
        
          unordered_map<int, vector<int>> graphMap;
    
    // Iterate over the adjacency list
         for (int i = 0; i < adj.size(); i++) {
        graphMap[i] = adj[i]; // Assign the adjacency list for vertex i
         }
         int V=graphMap.size();
        vector<int> result;
        vector<bool> visited(V,false);
        
        DFS(visited,result,0,graphMap);
        
        return result;
        
    }
