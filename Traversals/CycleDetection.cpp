queue<pair<int,int>> q;
        q.push({0,-1}) //{node,parent}
        
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            
            int node=p.first;
            int parent=p.second;
            
            for(auto &v: adj[node]){
                if(!visited[v]){
                    visited[v]=true;
                    q.push({v,node})
                }else if(v!=parent){
                    return true; //cycle detected
                }
                
            }
        }
        
        return false;
