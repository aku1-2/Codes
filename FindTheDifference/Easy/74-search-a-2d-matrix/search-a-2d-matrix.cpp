class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int m = matrix.size();
       int n =matrix[0].size();
       int srow=0,scol=0,erow=m-1,ecol=n-1;
       bool found=false;
       while(srow<=erow && scol<=ecol){
             for(int i=scol;i<=ecol;i++){
                if(target==matrix[srow][i]){ 
                  found=true;
                  break;
                  }
             }
             for(int i=srow+1;i<=erow;i++){
                if(target==matrix[i][ecol]){ 
                found=true;
                break;
                }
             }
             for(int i=ecol;i>=scol;i--){
                //if(srow==erow) break;
                if(target==matrix[erow][i]){ 
                found=true;
                break;
                }
             }
             for(int i=erow-1;i>=srow+1;i--){
                //if(scol==ecol) break;
                if(target==matrix[i][scol]){ 
                found=true;
                break;
                }
             }
             srow++;
             scol++;
             erow--;
             ecol--;
       }
          return found;
    }
};