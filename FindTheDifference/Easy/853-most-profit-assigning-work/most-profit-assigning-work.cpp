class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>>values;
        int best=0;
        for(int i=0;i<difficulty.size();i++)
              values.push_back({difficulty[i],profit[i]});

              sort(values.begin(),values.end());
              sort(worker.begin(),worker.end());
              int i=0;
              int total=0;
            for(auto w: worker){ 
             while(w>=values[i].first && i<values.size() ){
                  best=max(best, values[i].second);
                  i++;
             }
             total += best;
        
            }
            return total;
    }
};