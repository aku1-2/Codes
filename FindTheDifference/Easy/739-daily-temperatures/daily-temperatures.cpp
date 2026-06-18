class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n= temperatures.size();
       stack<int> s;
       vector<int> answer(n);
       for(int i=0;i<n;i++){
           while(!s.empty() && temperatures[i]>temperatures[s.top()]){
             int diff = s.top();
             s.pop();
             answer[diff] = i-diff;
           }
           s.push(i);
       }
       return answer;
    }
};