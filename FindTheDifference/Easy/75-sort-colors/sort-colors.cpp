class Solution {
public:
    void sortColors(vector<int>& nums) {
        int k;
       for(int i=0;i<nums.size()-1;i++){
        for(int j=0;j<nums.size()-i-1;j++){
            if(nums[j]>nums[j+1]){ 
            k=nums[j+1];
            nums[j+1]=nums[j];
            nums[j]=k;}
        }
       } 
    }
};