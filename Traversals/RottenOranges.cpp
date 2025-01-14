class Solution{
public:

  int minTime(vector<vector<int>> grid){
    int m=grid[0].size();
    int n=grid.size();

    int fresh=0; //count of the fresh mangoes
    for(int i=0;i<m;i++){
      for(int j=0;j<n;j++){
        if(grid[i][j]==2){
          //push the index in the queue
          q.push({i,j});
        }
        if(grid[i][j]==1){
          fresh++;
        }
      } 
    }

    //at the end check run two loops if fresh orange is found return 0 as all can not be made rottened
  }


}
