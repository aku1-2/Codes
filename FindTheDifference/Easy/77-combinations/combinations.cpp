class Solution {
public:
    vector<vector<int>> ans;
    vector<int> t;
    void helper(int index, int n,int k){
        if(t.size()==k){
            ans.push_back(t);
            return;
        }

        for(int i=index; i<=n; i++){
            t.push_back(i);
            helper(i+1 , n ,k);
            t.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        helper(1,n,k);
        return ans;
    }
};