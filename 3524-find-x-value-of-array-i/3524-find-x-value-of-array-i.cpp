class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
         vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> newDp(k, 0);

            // Subarray containing only num
            newDp[num % k]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                if (dp[r] > 0) {
                    int newR = (1LL * r * num) % k;
                    newDp[newR] += dp[r];
                }
            }

            dp = newDp;

            // All subarrays ending at current position
            for (int r = 0; r < k; r++) {
                result[r] += dp[r];
            }
        }

        return result;
    }
};