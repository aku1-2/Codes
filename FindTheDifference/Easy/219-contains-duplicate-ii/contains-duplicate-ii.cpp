class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        /*for(int i=0;i<nums.size();i++){
           for(int j=max(0,i-k);j<i;j++){ 
            if(nums[i]==nums[j]) {
                    return true;
            }
        }
        }
        return false;*/



        //map
        unordered_map<int,int> index;
        for(int i=0;i<nums.size();i++){
            if(index.count(nums[i])){
                if(i-index[nums[i]]<=k){
                    return true;
                }
            }
            index[nums[i]]=i;
        }
        return false;
    }
};