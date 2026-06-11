class Solution {
public:
    vector<string> ans;

    void subsets(string s, int open, int close, int n) {
        if (s.length() == 2 * n) {
            ans.push_back(s);
        }

        if (open < n) {
            subsets(s + "(", open + 1, close, n);
        }

        if (close < open) {
            subsets(s + ")", open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        subsets("", 0, 0, n);
        return ans;
    }
};