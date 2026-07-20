class Solution {
public:
vector<vector<int>> ans;
vector<int>path;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> used(nums.size(),false);
        backtrack(nums,used);
        return ans;
    }
    void backtrack(vector<int>& nums, vector<int>& used){
        if(path.size()==nums.size())
        {
            ans.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i])
            continue;
            if( i>0 && nums[i]==nums[i-1] && !used[i-1] )
            continue;

            used[i]=true;
            path.push_back(nums[i]);
            backtrack(nums, used);
            path.pop_back();
            used[i]=false;
        }
    }
};