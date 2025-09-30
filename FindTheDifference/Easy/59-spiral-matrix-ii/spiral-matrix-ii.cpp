class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int srow=0,scol=0,erow=n-1,ecol=n-1;
        int k=1;
        vector<vector<int>> mat(n,vector<int>(n));
        //vector<vector<int>> ans;

        while(srow<=erow && scol<=ecol){
       //top
       for(int i=scol;i<=ecol;i++){
        mat[srow][i]=k;
        k++;
       }
//right
       for(int i=srow+1;i<=erow;i++){
        mat[i][ecol]=k;
        k++;
       }

       for(int i=ecol-1;i>=scol;i--){
        if(srow==erow)
        break;
        mat[erow][i]=k;
        k++;
       }

       for(int i=erow-1;i>=srow+1;i--){
        if(scol==ecol)
        break;
        mat[i][scol]=k;
        k++;
       }
       srow++; scol++;erow--;ecol--;
        }
        return mat;
    }
};