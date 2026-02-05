class Solution {
public:
    string removeDuplicateLetters(string s) {
       vector<int> lastindex(26,0);
       vector<bool> seen(26,0);
       for(int i=0;i<s.size();i++){
        lastindex[s[i]-'a'] =i;
       }
           stack<char> st;
           for(int i=0;i<s.size();i++){
            int curr = s[i] - 'a';
            if(seen[curr]== true) continue;
            while(!st.empty() && st.top()>s[i] && i<lastindex[st.top()-'a']){ 
            seen[st.top()-'a']= false;
            st.pop();
           }
           st.push(s[i]);
           seen[curr]= true;
           }
           string str ="";
           while(st.size()>0){
            str += st.top();
            st.pop();
           }
           reverse(str.begin(),str.end());
           return str;
    }
};