
class Solution {
public:
    vector<vector<int>> ans;
    vector<int>help;
    void helper(int index, vector<int>& candidates, int target){
        if(target==0){
            ans.push_back(help);
            return;
        }
        for(int i= index; i<candidates.size();i++){ 

        if(i>index && candidates[i]== candidates[i-1])
            continue;
            if(candidates[i]>target)
              break;
            help.push_back(candidates[i]);
            helper(i+1, candidates, target - candidates[i]);
            help.pop_back();
          
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
       helper(0, candidates, target);
       return ans;
    }
};        
 