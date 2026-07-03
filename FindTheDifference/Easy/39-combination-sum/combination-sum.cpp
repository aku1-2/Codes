class Solution {
public:
    vector<vector<int>> ans;
    vector<int>help;
    void helper(int index, vector<int>& candidates, int target){
        if(target==0){
            ans.push_back(help);
            return;
        }
        if(index== candidates.size())
             return;

        if(candidates[index] <= target){
            help.push_back(candidates[index]);
            helper(index, candidates, target - candidates[index]);
            help.pop_back();
        }
        helper(index+1, candidates, target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       helper(0, candidates, target);
       return ans;
    }
};