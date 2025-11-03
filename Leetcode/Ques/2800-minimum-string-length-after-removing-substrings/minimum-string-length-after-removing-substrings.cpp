class Solution {
public:
    int minLength(string s) {
        string str;
        for(char c: s){
            if(!str.empty()){ 
                char top = str.back();
                  if((top=='A' && c=='B') || (top=='C' && c=='D')){ 
                  str.pop_back();
                  continue;
                  }
            }
             
            str.push_back(c);
            
        }
        return str.length();
    }
};