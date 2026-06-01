class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
       /* unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){ 
        int compliment=target-nums[i];
        if(m.find(compliment) !=m.end()){
            return {m[compliment],i};
        }
        m[nums[i]]=i;
    }
   return {};*/
   vector<int> ans;
    for(int i=0;i<nums.size();i++){
         int a = target- nums[i];
         for(int j=0;j<nums.size();j++){
            if(nums[j]==a && i!=j)
                {
                     ans.push_back(i);
                     ans.push_back(j);
                     return ans;
                 }
             }
         }
     return {};
   }
};