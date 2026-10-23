class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        int maxk=INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=i){
                 //maxk= nums[i]&i;
                maxk &= nums[i];
            }



        }
        return maxk==INT_MAX?0:maxk;
    }
};