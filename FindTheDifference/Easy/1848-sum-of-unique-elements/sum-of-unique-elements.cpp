class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> freq(101,0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]]++;
        }
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(freq[nums[i]]>1)
              continue;
            sum += nums[i];
        }
        return sum;
    }
};