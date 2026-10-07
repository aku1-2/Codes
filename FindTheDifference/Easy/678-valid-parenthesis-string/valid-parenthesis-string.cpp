class Solution {
public:
    bool checkValidString(string s) {
       int low=0,high=0;
       for(char c:s){
        if(c=='('){
            low++;
            high++;
        }
        else if(c==')'){
            low--;
            high--;
            low= max(0,low);
        }
        else{
            low--;
            high++;
            low=max(0,low);
        }
        if(high<0)
        return false;
       }
       return low==0;
    }
};