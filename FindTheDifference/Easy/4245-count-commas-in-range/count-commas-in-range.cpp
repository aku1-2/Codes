class Solution {
public:
    int countCommas(int n) {
        int num=n;
        int d=0;
        while(num>0){
           num/=10;
           d++;
        }
        if(d<4)
        return 0;
        return (n-999);

    }
};