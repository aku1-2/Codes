class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        int totalnumbers = 1<<n;//2^n
        for(int i=0;i<totalnumbers;i++){
            ans.push_back(i^(i >> 1));
        }
        return ans;
    }
};