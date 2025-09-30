class Solution {
public:
    int findLHS(vector<int>& nums) {
        int k=nums.size();
        vector<pair<int,int>> v;
        int count=1;
        int sum=0;
        int maxlen=0;
       /* for(int i=0;i<k;i++){ 
            if(find_if(v.begin(),v.end(),[&](pair<int,int> p) { return p.first==nums[i];})==v.end()){

            count = 0;
            for(int j=0;j<k;j++){
               if(nums[j]==nums[i])
                   count++;           
            }
            
            v.push_back(make_pair(nums[i],count));
            }
        }*/

    sort(nums.begin(),nums.end());
    for(int i=1;i<=k;i++){
        if(i<k && nums[i]==nums[i-1]){
            count++;
        }
        else{
            v.push_back({nums[i-1],count});
            count=1;
        }
    }

       // sort(v.begin(),v.end());
        int l=v.size();
        for(int i=0;i<l-1;i++){
            if(v[i+1].first-v[i].first==1|| v[i+1].first-v[i].first==-1)
               sum=v[i+1].second + v[i].second;
              maxlen=max(maxlen,sum);
        }
        return maxlen;
    }
};