class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        int maxfreq = 0;
        int result = 0;

        // Step 1: Find the maximum frequency
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    count++;
                }
            }
            if (count > maxfreq) {
                maxfreq = count;
            }
        }

        // Step 2: Add up all elements that have maxfreq
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (nums[j] == nums[i]) {
                    count++;
                }
            }
            if (count == maxfreq) {
                result++; // count every occurrence
            }
        }

        return result;
    }
};
