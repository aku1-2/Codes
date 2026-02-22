class Solution {
public:
    int binaryGap(int n) {
     int last=-1, index=0;
     int maxdist=0;
     while(n>0){
        if(n&1){
            if(last !=-1)
            maxdist = max(maxdist,index-last);
            last =index;
        }
        n >>= 1;
        index++;
     }
     return maxdist;
        
    }
};