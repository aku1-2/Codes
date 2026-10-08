class Solution {
public:
    string removeOuterParentheses(string s) {
        string ch;
        int update=0;
        for(int i=0; i<s.size();i++){
               if(s[i]=='('){
                if(update>0)
                ch+=s[i];
                update++;
               }
               
               else {
                update--;
                if(update>0)
                ch+= s[i];
               }
        }
        return ch;
    }
};