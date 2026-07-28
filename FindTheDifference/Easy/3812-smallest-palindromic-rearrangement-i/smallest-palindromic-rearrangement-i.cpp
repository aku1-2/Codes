class Solution {
public:
    string smallestPalindrome(string s) {
        int mid = s.size() / 2;

        string s1 = s.substr(0, mid);
        sort(s1.begin(), s1.end());

        string ans = s1;

        if (s.size() % 2) {
            ans += s[mid];
        }

        string s2 = s1;
        reverse(s2.begin(), s2.end());

        ans += s2;

        return ans;
    }
};