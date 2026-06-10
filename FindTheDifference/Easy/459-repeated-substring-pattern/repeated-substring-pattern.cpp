class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string newstring = s+s;
        newstring = newstring.substr(1,newstring.size()-2);
        if(newstring.find(s)!= string::npos){
            return true;
        }
    return false;
;    }
};