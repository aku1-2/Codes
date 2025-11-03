class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
         unordered_map<int,int> remaindermap;
         remaindermap[0]=-1;
         int remainder=0;
         int sum=0;
         int prev_remainder=0;
         for(int i=0;i<n;i++){
            sum += nums[i];
            remainder=sum%k;
            if(remaindermap.count(remainder)){
                prev_remainder=remaindermap[remainder];
            
            if(i-prev_remainder>=2){
                return true;
            }
            }
            else{
                remaindermap[remainder]=i;
            }
         }
  return false;
         }
};