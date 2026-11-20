/*class Solution {
public:
vector<vector<int>>memo;
int findVal(vector<int>& nums, int start,int target){
    int j = lower_bound(nums.begin()+start,nums.end(),target)- nums.begin();
    if(j<nums.size() && nums[j]==target)
    return j;
    return -1;
}
int helper(int i,int increment,vector<int>& nums ){
    if(memo[i][increment]!=-1){
        return memo[i][increment];
    }
   int curr=nums[i]+increment;
   int len=1;
   int j= findVal(nums,i+1,curr+1);
   if(j!=-1){
    len = max(len,1+helper(j,0,nums));
   }
    j= findVal(nums,i+1,curr);
   if(j!=-1){
    len = max(len,1+helper(j,1,nums));
   }
   return memo[i][increment]=len;
}
    int maxSelectedElements(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        sort(nums.begin(),nums.end());
       memo.assign(n+1,vector<int>(2,-1));
        for(int i=0;i<n;i++){
            ans= max({helper(i,0,nums),helper(i,1,nums),ans}); 
        }
        return ans;

    }
};*/

class Solution {
public:
    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int, int> dp;
        int ans = 0;

        for (int x : nums) {
            dp[x + 1] = dp[x] + 1;
            dp[x] = dp[x - 1] + 1;

            ans = max({ans, dp[x], dp[x + 1]});
        }

        return ans;
    }
};