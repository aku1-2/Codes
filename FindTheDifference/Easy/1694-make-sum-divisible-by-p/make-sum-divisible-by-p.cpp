class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int,int> mp;
         long long sum=0;
         for(int i=0;i<nums.size();i++){
            sum+=nums[i];
         }
        int rem = sum%p;
        if(rem==0)
          return 0;
          long long prefix =0;
          int ans=nums.size();
         mp[0]=-1;
         for(int i=0;i<nums.size();i++){
          prefix = (prefix + nums[i]) % p;
          int t = (prefix- rem +p)%p;
          if(mp.find(t) != mp.end()){
            ans = min(ans, i- mp[t]);
          }
           mp[prefix]=i;
         }
         return ans!=nums.size()?ans:-1;

    }
};