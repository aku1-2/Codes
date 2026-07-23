class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        if(nums.size()<3)
          return nums.size();
        int x=nums.size();
        int bits=0;
        while(x){
            bits++;
            x >>=1;
        }
        return 1 << bits;
    }
};