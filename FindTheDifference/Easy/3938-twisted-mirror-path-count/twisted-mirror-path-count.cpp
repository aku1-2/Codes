class Solution {
public:
int Mod= 1e9+7;
int left=0,up=1;

   int solve(vector<vector<int>>& grid,int i,int j,int cameFrom,  vector<vector<vector<int>>>& t){
    int m=grid.size();
    int n=grid[0].size();
    if(i==m || j==n) return 0;
    if(i==m-1 && j==n-1) return 1;

    if(t[i][j][cameFrom]!=-1){
        return t[i][j][cameFrom];
            }

    if(grid[i][j]==1){
        if(cameFrom==left){
            return t[i][j][cameFrom]=solve(grid,i+1,j,up,t);
        }
        else{
            return t[i][j][cameFrom]=solve(grid,i,j+1,left,t);
        }
    }

    int total=0;
    total = (total + solve(grid,i,j+1,left,t))%Mod;
    total = (total + solve(grid,i+1,j,up,t))%Mod;
return t[i][j][cameFrom]=total;
   }

    int uniquePaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n=grid[0].size();
        vector<vector<vector<int>>> t(m+1,vector<vector<int>>(n+1,vector<int>(2,-1)));
        return solve(grid,0,0,left,t);
        
    }
};