class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> m;
        int count =0;
        bool odd=false;
        for(char c:s){
            m[c]++;
        }
        for(auto a: m){
            if(a.second%2==0)
               count += a.second;
            else{
                count += a.second-1;
                odd= true;
            }
        }
        if(odd)
          count++;
          return count;

    }
};