class Solution {
public:
    int findMin(vector<int>& nums) {
        int min=nums[0];
        for(int j=0;j<nums.size();j++){
            if(min>nums[j])
            min=nums[j];
        }
    return min;
    }
};