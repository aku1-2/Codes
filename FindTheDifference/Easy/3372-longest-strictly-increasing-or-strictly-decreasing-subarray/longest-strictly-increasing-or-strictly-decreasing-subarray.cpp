class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size(); 
        int maxsize=1;
        for(int i=0;i<n;i++){
            int Isize=1;
            int Dsize=1;
            for(int j=i+1;j<n;j++){
                if(nums[j-1]<nums[j]){
                    Isize++;
                    Dsize=1;
                }
                else if(nums[j-1]>nums[j]){
                    Dsize++;
                    Isize=1;
                }
                else
                break;
                              maxsize=max(maxsize,max(Dsize,Isize));

            }
        }
        return maxsize;
    }
};