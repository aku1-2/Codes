class Solution {
public:
    bool hasAllCodes(string s, int k) {
         unordered_set<string> substrings;
         int total = 1<<k;//2power k substrings will be total amount of substrings
         for(int i=0; i+k<=s.size();i++){
        string a= s.substr(i,k);
        substrings.insert(a);
        if(substrings.size()==total) return true;
         }
    return (substrings.size()==total);
    }
};