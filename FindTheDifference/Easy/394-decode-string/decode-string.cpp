class Solution {
public:
    string decodeString(string s) {
        stack<int> st1;
        stack<string> st2;
        string ans = "";
        int num = 0;

        for (char ch : s){
            if (isdigit(ch)){
                num = num * 10 + (ch - '0');
            }

            else if (ch == '['){
                st1.push(num);
                st2.push(ans);
                num = 0;
                ans = "";
            }

            else if (ch == ']'){
                int k = st1.top();
                st1.pop();
                string temp = st2.top();
                st2.pop();

                while (k--){
                    temp += ans;
                }
                ans = temp;
            }
            else{ 
                ans += ch;
        }
        }
        return ans;
    }
};