class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
       long sum=0 ; int res=0;
       int end=0, start=0;
       sort(nums.begin(),nums.end());
        while(end<nums.size()){
            sum=sum+nums[end++];
            if(k+sum<((long)nums[end-1]*(end-start))){
                sum=sum-nums[start++];
            }
            res=max(res,end-start);
        } 
       return res;
    }
};