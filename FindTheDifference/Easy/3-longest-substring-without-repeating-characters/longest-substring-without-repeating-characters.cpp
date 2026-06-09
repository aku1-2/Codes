class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result=0;
        for(int i=0;i<s.size();i++){
            vector<int> freq(256,0);
            for(int j=i;j<s.size();j++){
                freq[s[j]]++;
                if(freq[s[j]]>1)
                   break;
                   result = max(result,j-i+1);
                
            }
        }
        return result;
    }
};