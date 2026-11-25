class Solution {
public:
unordered_map<long long,int>mp;
int md= 1e9+7;

bool check(vector<int>& nums, int mid,int base){
    mp.clear();
    int n=nums.size();
    long long p=1;
   
    for(int k = 1; k < mid; k++)
           p = (p * base) % md;
    long long hash=0;
    int i=0,j=0;
    while(j<n){
        hash= (hash*base+nums[j])%md;
        if(j-i+1<mid){
            j++;
        }
        else{
            mp[hash]++;
            hash= (hash-nums[i]*p%md +md)%md;
            i++;
            j++;
        }
    }
    for(auto &m:mp){
       if(m.second==1)
       return true;
    }
    return false;
}

    int smallestUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        int base=*max_element(nums.begin(),nums.end());  
         int l=1,r=n,result=n;
        while(l<=r){
        int mid= l+((r-l)/2);
        if(check(nums,mid,base)){
            result= mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
       }
       return result;
    }
};