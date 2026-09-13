class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        auto n = max_element(nums.begin(),nums.end());
        auto m= min_element(nums.begin(),nums.end());
        long long ans= 1LL* k* (*n-*m);
        return ans;
    }
};