class Solution {
public:
    bool canAliceWin(int n) {
        bool alice=false;
      int i=10;
      if(n==10){
        return true;
      }
      if(n>10){
        
        while(n>=i && i>=1){ 
            if(n>=i && i%2==0){ 
                n=n-i;
                alice=true;
            }
            else if(n>=i && i%2==1){
                n=n-i;
                alice =false;
            }
            i--;
           
        }
      }
      return alice;
    }
};