class Solution {
public:

   
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();   //number of rows
        int n=mat[0].size();//number of columns

        vector<vector<int>> dis(m, vector<int>(n, -1)); 

        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    dis[i][j]=0;
                }
                
            }
        }

        while(!q.empty()){
            auto p=q.front();
            q.pop();

            int x1=p.first;
            int y1=p.second;

            int ax[]={-1,1,0,0};
            int ay[]={0,0,-1,1};

            for(int i=0;i<4;i++){
                int x=ax[i]+x1;
                int y=ay[i]+y1;

                if(x>=0 && x<m && y>=0 &&y<n && dis[x][y]==-1){
                    dis[x][y]=dis[x1][y1]+1;
                    q.push({x,y});
                }
                    
                
            }
        }
        return dis;
        
    }
};
