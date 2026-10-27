class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans(m,string(n,'#'));
        for(int j=0;j<m;j++){
            ans[j][0]='.';
        }
        int i=m-1;
        for(int j=0;j<n;j++){
            ans[i][j]='.';
        }
        return ans;
    }
};