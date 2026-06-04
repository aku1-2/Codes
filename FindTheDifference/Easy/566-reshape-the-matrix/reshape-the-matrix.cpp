class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m= mat.size();
        int n= mat[0].size();
        if((m*n)!=(r*c))
        return mat;
        vector<vector<int>> reshape(r,vector<int>(c));
        vector<int> a;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
             a.push_back(mat[i][j]);
            }
        }
        int s=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
             reshape[i][j]=a[s++];
            }
        }
        return reshape;
    }
};