class Solution {
public:
    int concatenatedBinary(int n) {
        const int MOD = 1e9 + 7;
        long long result=0;
        int bits=0, temp;
        for(int i=1;i<=n;i++){
            temp=i;
            while(temp>0){
                bits++;
                temp >>= 1;
            }
            result = ((result<<bits) % MOD +i)% MOD;
            bits=0;
        }
        return (int)result;
    }
};