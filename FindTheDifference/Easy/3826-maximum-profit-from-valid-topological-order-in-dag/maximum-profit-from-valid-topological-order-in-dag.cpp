class Solution {
public:
    int maxProfit(int n, vector<vector<int>>& edges, vector<int>& score) {
        const int maxMask = 1 << n;
        
        vector<int> need(n);
        
        vector<int> dp(maxMask, -1);
        dp[0] = 0;
        
        for (const vector<int>& edge : edges) {
            const int u = edge[0];
            const int v = edge[1];
            need[v] |= 1 << u;
        }
        
        
        for (unsigned mask = 0; mask < maxMask; ++mask) {
            if (dp[mask] == -1)
                continue;
            
            const int pos = __builtin_popcount(mask) + 1;
            
            for (int i = 0; i < n; ++i) {
                if (mask >> i & 1)
                    continue;
                
                if ((mask & need[i]) == need[i]) {
                    const int newMask = mask | 1 << i; 
                    dp[newMask] = max(dp[newMask], dp[mask] + score[i] * pos);
                }
            }
        }
        return dp.back();
    }
};