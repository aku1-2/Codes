class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<int>freq(128,0);
        for(auto x: stones){
            freq[x]++;
        }
        int sum=0;
        for(char c: jewels){
           sum+= freq[c];
        }
        return sum;
    }
};