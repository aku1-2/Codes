class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9*num < sum || sum <0)
        return "";
        string ans="";
        for(int i=0;i<num;i++){
            int d= min(9,sum);
             ans+= d+'0';
             sum-=d;
        }
        return ans;
    }
};