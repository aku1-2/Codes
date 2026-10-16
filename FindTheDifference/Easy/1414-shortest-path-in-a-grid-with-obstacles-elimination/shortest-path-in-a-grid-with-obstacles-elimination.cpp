class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        queue<array<int,4>>q;
        q.push({0,0,k,0});
        
        int dx[4]={-1,1,0,0};
        int dy[4]={0,0,-1,1};
        vector<vector<vector<int>>> vis(m,vector<vector<int>>(n,vector<int>(k+1,0)));
        vis[0][0][k]=1;
        while(!q.empty()){
           auto [i,j,newrem,score]=q.front();
            q.pop();
            if(i==m-1 && j==n-1)
            return score;
             for(int l=0;l<4;l++){
                int x= i+dx[l];
                int y=j+dy[l];

                if(!(x>=0 && x<m && y>=0 && y<n))
                continue;
                int ne= newrem-grid[x][y];
                if(ne<0){
                    continue;
                }
                if(vis[x][y][ne])
                continue;
                vis[x][y][ne]=1;
                    q.push({x,y,ne,score+1});
                }
             }
        
        return -1;
    }
};