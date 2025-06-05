class Solution {
public:
    vector<int> rank;
    vector<int> parent;
    int find(vector<int>&parent, int x){
        if (parent[x] != x)
            parent[x] = find(parent, parent[x]);
        return parent[x];
    }

    void _Union(int x, int y){
        int x_par=find(parent,x);
        int y_par=find(parent,y);

        if(x_par==y_par){
            return;
        }

        if(x_par<y_par){
            parent[y_par]=x_par;
        }else{
            parent[x_par]=y_par;
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        string res;
        int n=s1.length();
        int sz=baseStr.size();
        parent.resize(26);
        rank.resize(26,0);
        for(int i=1;i<26;i++){
            parent[i]=i;
        }

        for(int i=0;i<n;i++){
            char c1=s1[i];
            char c2=s2[i];
            _Union(c1-'a',c2-'a');
        }

        for(auto i: baseStr){
            int p=find(parent,i-'a');
            res+=(char)(p+'a');
        }

        return res;
    }
};
