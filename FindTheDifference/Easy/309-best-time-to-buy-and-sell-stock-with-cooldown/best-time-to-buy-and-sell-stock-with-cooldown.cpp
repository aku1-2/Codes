class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int h = -(prices[0]);
        int sell = 0;
        int rest = 0;
        for(int i=0;i<prices.size();i++){
            int prevH = h;
            int prevSold= sell;
            int prevRest = rest;
            h= max(prevH, prevRest-prices[i]);
            sell= prevH + prices[i];
            rest = max(prevRest, prevSold);
        }
        return max(sell,rest);
    }
};