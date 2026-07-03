class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string, int> mp;
        string word;
        unordered_set<string> ban(banned.begin(), banned.end());
        for (char &c : paragraph) {
            if (isalpha(c))
                c = tolower(c);
            else
                c = ' ';
        }
         stringstream ss(paragraph);
        while (ss >> word) {
            if (ban.find(word) == ban.end()) {
                mp[word]++;
            }
        }

        string ans;
        int maxi = 0;

        for (auto x : mp) {
            if (x.second > maxi) {
                maxi = x.second;
                ans = x.first;
            }
        }

        return ans;
    }
};