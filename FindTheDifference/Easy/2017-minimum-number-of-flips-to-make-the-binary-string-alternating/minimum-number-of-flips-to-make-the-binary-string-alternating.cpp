class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string s2 = s + s;

        int ans = INT_MAX;
        int diff1 = 0, diff2 = 0;

        for(int i = 0; i < s2.size(); i++){

            char p1 = (i % 2) ? '1' : '0';
            char p2 = (i % 2) ? '0' : '1';

            if(s2[i] != p1) diff1++;
            if(s2[i] != p2) diff2++;

            if(i >= n){
                char p1_old = ((i-n) % 2) ? '1' : '0';
                char p2_old = ((i-n) % 2) ? '0' : '1';

                if(s2[i-n] != p1_old) diff1--;
                if(s2[i-n] != p2_old) diff2--;
            }

            if(i >= n-1){
                ans = min(ans, min(diff1, diff2));
            }
        }

        return ans;
    }
};