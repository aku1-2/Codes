class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        vector<pair<string,int>> v;
        vector<string>ans;

        for(string word: words)
           m[word]++;
        for(auto c: m)
            v.push_back(c);

        sort(v.begin(),v.end(),help);

        for(int i=0;i<k;i++){
            ans.push_back(v[i].first);
        }
        return ans;

    }
    static bool help(pair<string,int>& a, pair<string,int>& b){
        if(a.second== b.second){
            return a.first<b.first;
        }
        return a.second>b.second;
    }
};