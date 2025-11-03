class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int left=0 , right=0;
        int isDeleted =false;
        int ans=0 , value=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
               ans= isDeleted?(max(ans,i-left)):(max(ans,i-left+1));
            }
            else{
                if(isDeleted){
                    while(nums[left]==1){ 
                    left=left+1;
                }
                left=left+1;
                }
                else{ 
                isDeleted=true;
                }
            }
        }
         return isDeleted?ans:ans-1;
    }
};