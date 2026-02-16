class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        queue<pair<pair<int,int> , int>> q; // distance also 
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return -1;
          q.push({{0,0},1});
          vis[0][0]=1;
          int dx [8]={1,1,1,0,0,-1,-1,-1};
          int dy [8]= {-1,0,1,-1,1,-1,0,1};

          while(!q.empty()){
            auto [index , dis] = q.front();
            auto [x,y] =index;
            q.pop();
            if(x==n-1 && y == n-1) return dis;

            for(int j=0;j<8 ; j++){
                int nx = x+ dx[j];
                int ny = y+ dy[j];

                if(nx>=0 && ny>= 0 && nx<n && ny<n && grid[nx][ny]==0 && vis[nx][ny]==0){
                    q.push({{nx,ny}, dis+1});
                    vis[nx][ny]=1;
                }
            }
          }
          return -1;
    }
};