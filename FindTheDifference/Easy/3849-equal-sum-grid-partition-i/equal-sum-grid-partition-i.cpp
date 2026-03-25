class Solution {
   
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m =grid.size();
        int n=grid[0].size();
        long long sum=0 , totalsum=0;
       
        for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                  totalsum += grid[i][j];
                }
        }
        if(totalsum%2!=0) return false;
              
        for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                  sum += grid[i][j];
                }
                if(sum== totalsum/2) return true;
        }
         sum=0;
         for(int j=0;j<n;j++){
                for(int i=0;i<m;i++){
                  sum += grid[i][j];
                }
                if(sum == totalsum/2) return true;
        }
      
        return false;
    }
};