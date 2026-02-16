class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n= grid.size();
        //vector<vector<int>> vis(n, vector<int>(n,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                }
            }
            }
            if(q.empty() || q.size()==n*n) return -1;
            int dx[4]={1,-1,0,0};
            int dy[4]={0,0,1,-1};
            int dist =-1;

            while(!q.empty()){
                int size= q.size();
                dist++;
                for(int i=0;i<size;i++){
                    auto [x,y]=q.front();
                     q.pop();

                    for(int j=0;j<4;j++){
                        int nx= x+dx[j];
                        int ny= y+dy[j];
                           
                           if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0){
                             grid[nx][ny]=1;//mark visited
                             q.push({nx,ny});

                           }
                    }
                }
            }
        
        return dist;
    }
};