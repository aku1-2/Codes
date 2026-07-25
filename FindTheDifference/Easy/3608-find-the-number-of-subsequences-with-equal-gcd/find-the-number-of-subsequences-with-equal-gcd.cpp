class Solution {
public:
int mod= 1e9+7;
int t[201][201][201];
     int solve(vector<int>& nums,int i, int firstGcd, int secondGcd ){
        if(i==nums.size()){
            bool notempty= (firstGcd!=0 && secondGcd!=0);
            bool match= firstGcd==secondGcd;
            return (notempty && match)?1:0;
        }
        if(t[i][firstGcd][secondGcd]!=-1){
            return t[i][firstGcd][secondGcd];
        }
      int skip= solve(nums,i+1, firstGcd, secondGcd);
      int pair1= solve(nums,i+1, gcd(firstGcd,nums[i]), secondGcd);
      int pair2= solve(nums,i+1, firstGcd, gcd(secondGcd,nums[i]));
      return t[i][firstGcd][secondGcd]=(0LL+skip+pair1+pair2)%mod;

     }
    int subsequencePairCount(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(nums,0,0,0);
    }
};