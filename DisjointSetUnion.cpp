//DISJOINT SET UNION AND FIND
class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(x==parent[x]){
            return x;
        }

        return parent[x]=find(parent[x]);
    }

    void Union(int x,int y){
        int x_parent=find(x);
        int y_parent=find(y);

        if(x_parent==y_parent){
            return ;
        }
        else if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }
        else{
            if(rank[x_parent]==rank[y_parent]){
                parent[x_parent]=y_parent;
                rank[y_parent]++;
            }
        }
    }

//n is number of nodes in graph
    int intialise(n)
{
    parent.resize(n);
    rank.resize(n);
}

};
