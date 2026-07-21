class Solution {
public:
vector<vector<int>> ans;
vector<int> current;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int index=0;
        generate(index,nums);
        return ans;
    }
    void generate( int index,vector<int>& nums){
       
            ans.push_back(current);
            
        for(int i=index;i<nums.size();i++){
            
            if(i>index && nums[i]==nums[i-1])
            continue;
            current.push_back(nums[i]);
            generate(i+1,nums);
            current.pop_back();
        }

    }
};