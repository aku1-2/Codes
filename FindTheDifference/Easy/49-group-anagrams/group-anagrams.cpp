class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        vector<vector<string>>ans;
        for (string s: strs) {
            string k= s;
            sort(k.begin(),k.end());

            m[k].push_back(s);
        }
        for (auto &i: m) {
            ans.push_back(i.second);// respective anagram pe uska strings honge key-anagram, strings saare second(value)
        }
        return ans;
    }
};