class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
       int n = nums1.size();
        long long k = 1LL * k1 + k2;

        vector<int> diff(n);
        int maxDiff = 0;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
            total += diff[i];
        }

        // Enough operations to make every difference zero
        if (k >= total) return 0;

        // Binary search the smallest level x such that
        // reducing every difference to at most x costs <= k.
        int left = 0, right = maxDiff;

        while (left < right) {
            int mid = left + (right - left) / 2;
            long long needed = 0;

            for (int d : diff) {
                if (d > mid) {
                    needed += d - mid;
                }
            }

            if (needed <= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        int x = left;
        long long used = 0;
        long long ans = 0;
        long long count = 0;

        for (int d : diff) {
            if (d > x) {
                used += d - x;
                ans += 1LL * x * x;
            } else {
                ans += 1LL * d * d;
            }

            // Differences at least x can be reduced to x - 1
            if (d >= x) count++;
        }

        // Use remaining operations to reduce some x values to x - 1
        long long remaining = k - used;
        ans -= remaining * (2LL * x - 1);

        return ans;
    }
};