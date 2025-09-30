class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int i=0;
       sort(strs.begin(),strs.end());
       string first=strs[0] , last=strs.back();
       while(i<first.size() && i<last.size() && first[i]==last[i]){
        i++;
       }
       return strs[0].substr(0,i);
    }
};