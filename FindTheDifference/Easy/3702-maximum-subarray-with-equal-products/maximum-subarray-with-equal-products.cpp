class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int mx=INT_MIN;
        
        for(int i=0;i<n;i++){
            int g=0;
            int l=1;
             long long prod=1;
            for(int j=i;j<n;j++){
                  g=gcd(g,nums[j]);
                  l=lcm(l,nums[j]);
                  if(prod>=2520*g*l)//comments se hai
                  break;
                  prod*=nums[j];
                  if(prod== l*g){
                    mx= max(mx,j-i+1);
                  }
            }
        }
        return mx;
    }
};