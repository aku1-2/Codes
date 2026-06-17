class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        if(s.size()%2!=0){
            return false;
        }
        for(int i=0;i<s.size();i++){
            //openeing case
            if(s[i]=='(' || s[i]=='[' || s[i]=='{' ){
                st.push(s[i]);
            }
            else{
                if(st.empty())
                return false;
                else
                {
                   if((st.top()=='(' && s[i]==')') ||(st.top()=='[' && s[i]==']') || (st.top()=='{' && s[i]=='}') )
                   st.pop();
                   else
                   return false;
                   
                }
            }
        }
        return st.size()==0;
    }
};