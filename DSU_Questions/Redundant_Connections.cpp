class Solution {
public:
    int V;
    vector<int> parent;
    vector<int> rank;

    int find(vector<int>& parent,int i){
        if(i==parent[i]){
            return i;
        }

        return parent[i]=find(parent,parent[i]);
    }

    void Union(int x,int y){
        int x_par=find(parent,x);
        int y_par=find(parent,y);
        if(x_par==y_par){
            return;
        }

        if(rank[x_par]>rank[y_par]){
            parent[y_par]=x_par;
        }else if(rank[y_par]>rank[x_par]){
            parent[x_par]=y_par;
        }else{
            if(rank[x_par]==rank[y_par]){
                parent[x_par]=y_par;
                rank[y_par]++;
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        V=edges.size();
        parent.resize(V+1);
        rank.resize(V+1,0);

        vector<int> result;
        for(int i=1;i<=V;i++){
           parent[i]=i;
        }

        for(auto edge: edges){
            int v=edge[0];
            int u=edge[1];

            if(find(parent,v)==find(parent,u)){
                return edge;
            }

            Union(u,v);
        }

        return {};
     


    }
};
