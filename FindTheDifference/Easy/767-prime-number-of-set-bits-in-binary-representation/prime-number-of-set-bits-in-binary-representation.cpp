class Solution {
public:
    int countPrimeSetBits(int left, int right) {
      int prime=0;
       int result=0;
        for(int i= left; i<=right; i++){
            int count=countset(i);
            for(int j=2;j<=count;j++){
                if(count %j ==0)
                prime++;  
            }
            if(prime==1)
            result++;
            count=0;
            prime=0;
        }
        return result;
    }

    int countset(int n){
        int count=0;
        while(n>0){ 
        if((n&1)==1){
            count++;
        }
        n >>= 1;
      }
      return count;
    }
};