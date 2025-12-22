class Solution {
public:
    int majorityElement(vector<int>& nums) {
        /*int maxcountelement=0;
        int count=0;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<nums.size();j++){
                if(nums[i]==nums[j])
                count++;
            }
           if(count>(nums.size()/2)){ 
            maxcountelement=nums[i];
            break;
            }
            count=0;
        }
        return maxcountelement;*/

//Boyar-Moore Voting Algoritm
        int count=0;
        int candidate;
        for(int i=0;i<nums.size();i++){
            if(count==0) candidate=nums[i];
            if(nums[i]==candidate) count++;
            else count--;
        }
        return candidate;
    }
};