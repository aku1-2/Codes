class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        return help(0,0,nums,target);
    }
    int help(int index, int sum,vector<int>& nums, int t ){
        if(index== nums.size()){
            return sum==t;
        }
        int add= help(index+1, sum+nums[index],nums, t);
        int sub= help(index+1, sum-nums[index],nums, t);
        return add+sub;
    }
};