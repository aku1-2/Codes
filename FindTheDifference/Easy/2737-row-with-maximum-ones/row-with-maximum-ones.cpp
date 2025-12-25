class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int maxcount=0;
        int count=0;
        int index=0;
        int row = mat.size();
        int col= mat[0].size();
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){ 
            if(mat[i][j]==1)
              count++;
        }
        if(count>maxcount){ 
        maxcount=max(maxcount,count);
        index=i;
        }
        count=0;
      }
      
      return {index,maxcount};
        
    }
};