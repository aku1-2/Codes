class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min = prices[0];
        int maxprof=0;
        for(int i=0;i<prices.size();i++){
             if(min>prices[i]){
                min = prices[i];
             }
                 maxprof = max(maxprof , prices[i]- min);
             
        }
       
         return maxprof;
    }
};