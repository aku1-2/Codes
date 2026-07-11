class Solution {
public:
    int findComplement(int num) {
        int ans=0,bit=1;
        while(num){
            if(!(num&1))
              ans |= bit;
            num>>=1;
            bit<<=1;
        }
        return ans;
    }
};