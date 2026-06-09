class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freq(26,0);
        for(char c:s1){
            freq[c-'a']++;
        }
        for(int i=0;i < s2.size();i++){
            string a = s2.substr(i,s1.size());
             vector<int> freq1(26,0);
            for(char c:a)
               freq1[c-'a']++;

               if(freq==freq1)
               return true;
               
        }
        return false;
        
    }
};