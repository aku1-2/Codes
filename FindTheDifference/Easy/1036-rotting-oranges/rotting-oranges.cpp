class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m= grid.size();
        int n=grid[0].size();
       int minute=0;
       int fresh=0;

       queue<pair<int,int>> q;
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==2){
                q.push({i,j});
            }
            else if(grid[i][j]==1){
                fresh++;
            }
          }
       }

    // up down right left movements 
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

    while(!q.empty()){
        int size =q.size();
        bool changed=false;
        for(int i=0;i<size;i++ ){
               auto [x,y]= q.front();
               q.pop();

                for(int j=0;j<4;j++){
                     int nx= x+dx[j];
                     int ny= y+dy[j];
                      if(nx >=0 && nx<m && ny>=0 && ny<n && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                        fresh--;
                        changed=true;
                      }
                                                                 
                 }
        }
        if(changed)minute++;
        
       }
       return fresh==0?minute:-1;

    }
};