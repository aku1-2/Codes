class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if(p.size()>s.size())
        return {};
        vector<int> freq1(26,0);
        vector<int> ans;
        for(char c : p){
            freq1[c-'a']++;
        }
        for(int i =0; i<= s.size()-p.size();i++){
            string a= s.substr(i,p.size());
             vector<int> freq2(26,0);
             for(char c : a)
                 freq2[c-'a']++;

                 if(freq2==freq1)
                   ans.push_back(i);

        }
        return ans;
    }
};