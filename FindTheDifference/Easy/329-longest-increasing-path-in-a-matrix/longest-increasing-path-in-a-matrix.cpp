class Solution {
public:
    vector<vector<int>>dp;
    int m,n;
    int dx[4]={-1,1,0,0};
    int dy[4]={0,0,-1,1};

  int dfs(vector<vector<int>>& arr, int i,int j){
    if(dp[i][j]!=0){
        return dp[i][j];
    }
    dp[i][j]=1;
    for(int l=0;l<4;l++){
        int x= i+dx[l];
        int y= j+dy[l];
        if(x>=0 && x<m && y>=0 && y<n && arr[x][y]>arr[i][j]){
            dp[i][j]=max(dp[i][j],1+dfs(arr,x,y));
        }
    }    
    return dp[i][j];

  }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m=matrix.size();
        n=matrix[0].size();
        int ans=0;
        dp.assign(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,dfs(matrix,i,j));
            }
        }
        return ans;
        
    }
};