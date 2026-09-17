class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m= grid.size();
        int n=grid[0].size();
        int mx= 0;
          int dx[4]= {-1,1,0,0};
          int dy[4]= {0,0,-1,1};
          int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                 {
                    count++;
                    grid[i][j]=0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        auto [x,y]= q.front();
                        q.pop();

                        for(int k=0;k<4;k++){
                            int nx= x+dx[k];
                            int ny= y+dy[k];
                            if(nx>=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                                count++;
                                grid[nx][ny]=0;
                                q.push({nx,ny});

                            } 
                        }

                    }
                 }
                 mx= max(mx,count);
                 count=0;
            }
        }
        return mx;
    }
};