class Solution {
  public:
  //To find Stringly Connected Components in the graph
  //Step 1: Store Topological order in the stack
  //Step 2: Reverse all the edges in the graph
  //Step 3: Call DFS on each node from Stack in order, number of DFS calls gives strongly connected components

    void DFS_topo(int i,vector<vector<int>> &adj,vector<bool> &visited, stack<int> &st){
        visited[i]=true;
        
        for(auto &v: adj[i]){
            if(!visited[v]){
                DFS_topo(v,adj,visited,st);
            }
        }
        
        st.push(i);
    }
    
    void DFS(int u,vector<vector<int>> &adjreversed,vector<bool> &visited){
        visited[u]=true;
        
        for(auto &v:adjreversed[u]){
            if(!visited[v]){
                DFS(v,adjreversed,visited);
            }
        }
    }
    
    int kosaraju(vector<vector<int>> &adj) {
         stack<int> st;
         int V=adj.size();
         vector<bool> visited(V,false);
         
         for(int i=0;i<V;i++){
             if(!visited[i]){
                 DFS_topo(i,adj,visited,st);
             }
         }
         
         int count=0;
         
         vector<vector<int>> adjreversed(V);
         for(int u=0;u<V;u++){
             
             for(auto &v:adj[u]){
                 adjreversed[v].push_back(u);
             }
         }
         
         visited=vector<bool> (V,false);
         while(!st.empty()){
             int node=st.top();
             st.pop();
             
             if(!visited[node]){
                 DFS(node,adjreversed,visited);
                 count++;
             }
         }
         
         
         return count;
         
    }
