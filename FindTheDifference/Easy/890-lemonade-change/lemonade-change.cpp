class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0]==10 || bills[0]==20)
        return false;
        int count5=0 ,c10=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){ 
                count5++;
            continue;
            }
            else if(bills[i]==10 ){
                if(count5==0) return false;
                c10++;
                count5--;
            }
            else {
                if(c10>0 &&count5>0){ 
                c10--;
                count5--;
                }
                else if(count5>=3){
                    count5-= 3;
                }
                else return false;
            }

        }
        return true;
    }
};