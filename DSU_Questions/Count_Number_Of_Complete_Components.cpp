class Solution {
public:
    vector<int> parent;
    vector<int> rank;
     int find(int i) {
        if (i == parent[i]) return i;
        return parent[i] = find(parent[i]); // Path compression
    }

    void union_find(int x,int y){
        int x_par=find(x);
        int y_par=find(y);

        if(x_par==y_par) return;

        if(rank[x_par]>rank[y_par]){
            parent[y_par]=x_par;
        }else if(rank[y_par]>rank[x_par]){
            parent[x_par]=y_par;
        }else{
            parent[x_par]=y_par;
            rank[y_par]++;
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int count=0;

        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i; // Each node is its own parent initially
        }

        unordered_map<int,vector<int>> mp;
        for(auto &edge: edges){
            int u=edge[0];
            int v=edge[1];
            mp[edge[0]].push_back(edge[1]);
            mp[edge[1]].push_back(edge[0]);
            union_find(u,v);
        }

        unordered_map<int,vector<int>> component;

        for(int i=0;i<n;i++){
            int par=find(i);
            component[par].push_back(i);

            //MAP Parent ---> children
            //0---> {0,1,2};
        }

        for(auto &c: component){
            vector<int> children=c.second;
            int s=children.size();

            bool isComplete=true;

            for(auto &node: children){
                if(mp[node].size()!=s-1){
                    isComplete=false;
                    break;
                }
            }

            if(isComplete){
                count++;
            }

        }

        return count;

    }
};
