class Solution {
public:
       string ans="";
       string curr="";
       unordered_set<string>st;

        void helper(int n){
           if(curr.size()==n){
            if(!st.count(curr)){
                ans= curr;
            }
            return;
           }

           curr.push_back('0');
           helper(n);
           curr.pop_back();

           curr.push_back('1');
           helper(n);
           curr.pop_back();
        }


    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        for(auto num : nums){
            st.insert(num);
        }
        helper(n);
        return ans;
    }
};