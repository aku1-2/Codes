class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        vector<vector<int>> ans;
        int index=0;
        generate(0,nums,current,ans);
        return ans;

    }
    void generate(int index, vector<int>&nums,vector<int>&current,vector<vector<int>>&ans){ 
         if(index==nums.size()){
            ans.push_back(current);
            return;
        }
        current.push_back(nums[index]);
        generate(index+1,nums,current,ans);
        current.pop_back();
        generate(index+1,nums,current,ans);
        }
};