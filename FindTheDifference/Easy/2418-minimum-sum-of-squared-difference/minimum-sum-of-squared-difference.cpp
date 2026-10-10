class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        vector<int> diff(n);
        int maxi = 0;
        long long k = 1LL * k1 + k2;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxi = max(maxi, diff[i]);
            sum += diff[i];
        }

        if (sum <= k) return 0;

        int low = 0, high = maxi;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long ops = 0;

            for (int d : diff) {
                ops += max(0, d - mid);
            }

            if (ops <= k)
                high = mid;
            else
                low = mid + 1;
        }

        long long ans = 0;
        long long used = 0;

        for (int d : diff) {
            int reduced = min(d, low);
            used += d - reduced;
            ans += 1LL * reduced * reduced;
        }

        k -= used;

        for (int d : diff) {
            if (k == 0) break;

            if (d >= low && low > 0) {
                ans -= 1LL * low * low;
                ans += 1LL * (low - 1) * (low - 1);
                k--;
            }
        }

        return ans;
    }
};