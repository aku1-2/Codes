class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        
        
        sort(nums.begin(),nums.end());
        if(nums.size()==3){
            return nums[0]*nums[1]*nums[2];
        }
        int j=1,i=nums.size()-1,prod1=1,prod2=1;
        while(j<=3){
            prod1 = prod1*nums[i];
            i--;
            j++;
        }
        prod2 = nums[0]*nums[1]*nums[nums.size()-1];
        return (prod1>prod2)?prod1:prod2;
    }
};