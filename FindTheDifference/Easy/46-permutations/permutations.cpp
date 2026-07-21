class Solution {
public:
vector<vector<int>> ans;
vector<int> path;
    vector<vector<int>> permute(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>used(nums.size(),false);
        backtrack(nums,used);
        return ans;
    }
       void  backtrack(vector<int>& nums,vector<int>& used){
        if(path.size()==nums.size()){
            ans.push_back(path);
        }
        for(int i=0;i<nums.size();i++){
            if(used[i])
             continue;
             used[i]=true;
             path.push_back(nums[i]);
             backtrack(nums,used);
             path.pop_back();
             used[i]=false;

        }
       }
};