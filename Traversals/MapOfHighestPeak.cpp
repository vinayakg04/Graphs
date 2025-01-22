class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();

        vector<vector<int>> height(n,vector<int> (m,-1));

        queue<pair<int,int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(isWater[i][j]==1){
                    height[i][j]=0;
                    q.push({i,j});
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
                int x=x1+ax[i];
                int y=y1+ay[i];

                if(x>=0 && x<n && y>=0 && y<m && height[x][y]==-1){
                    height[x][y]=1+height[x1][y1];
                    q.push({x,y});
                }
            }
        }


        return height;
    }
};
