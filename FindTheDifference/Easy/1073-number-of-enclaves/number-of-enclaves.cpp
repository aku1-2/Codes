class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
         int n = grid[0].size();
        queue<pair<int,int>> q;

        for(int i=0;i<m;i++){
            if(grid[i][0]==1) q.push({i,0});
            if(grid[i][n-1]==1) q.push({i,n-1});
        }

        for(int j=0;j<n;j++){
            if(grid[0][j]==1) q.push({0,j});
            if(grid[m-1][j]==1) q.push({m-1,j});
        }
        vector<vector<int>> dirs= {{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();

            if(x<0 || y<0 || x>=m || y>=n || grid[x][y]!=1) continue;
            grid[x][y]=0;//mark it as visited

            for(auto &a: dirs){
                q.push({x+a[0] , y+a[1]});
            }
        }

        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n; j++){
                if(grid[i][j]==1) count++;
            }
        }
    return count;
    }
};