class Solution {
public:

     int calSum(int n){
        int sum=0;
        while(n>0){
            int d=n%10;
            sum+=d;
            n/=10;
        }
        return sum;
     }

    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>>sum;
        for(int i=0;i<n;i++){
            sum.push_back({calSum(nums[i]),nums[i]});
        }
        sort(sum.begin(),sum.end());
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[sum[i].second]=i;
        }
        int total_cycle=0;
        vector<bool>vis(n,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                total_cycle++;
                int c=i;
                while(!vis[c]){
                    vis[c]=true;
                    c=mp[nums[c]];
                }
            }
        }
        return n-total_cycle;
    }
};