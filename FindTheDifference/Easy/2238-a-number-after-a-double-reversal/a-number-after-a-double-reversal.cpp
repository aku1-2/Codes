class Solution {
public:
    bool isSameAfterReversals(int num) {
       /* int d1=0,d2=0;
        int rev1=0,rev2=0;
         int n1=num;
        while(n1>0){
            d1=n1%10;
            rev1= rev1*10+d1;
            n1 /= 10;
        }
          int n2=rev1;
         while(n2>0){
            d2=n2%10;
            rev2 = rev2*10+d2;
            n2 /= 10;
        }
        return (rev2==num);*/

        if(num==0) return true;
        return ((num%10) !=0);
    }
};