class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        long long sum=0;
        long long mod=1e9+7;
        vector<int> count(32,0);
        for(auto num: nums){
            for(int i=0;i<32;i++){ 
            if(num & (1<<i)){
                count[i]++;
            }
            }
        }
        
        while(k--){ 
            long long  n=0;
        for(int i=0;i<32;i++){
            if(count[i]>0){
                count[i]--;
                n=n|(1<<i);
            }
        }
        sum = (sum+(n*n))%mod;
        }

      return sum;

    }
};