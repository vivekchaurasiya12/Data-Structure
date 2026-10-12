class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;
        vector<int> bitCount(32, 0);

        // Count set bits at each position.
        for (int num : nums) {
            for (int bit = 0; bit < 32; bit++) {
                if (num & (1LL << bit)) {
                    bitCount[bit]++;
                }
            }
        }

        long long ans = 0;

        // Build k numbers, maximizing each number greedily.
        for (int i = 0; i < k; i++) {
            long long curr = 0;

            for (int bit = 0; bit < 32; bit++) {
                if (bitCount[bit] > 0) {
                    curr |= (1LL << bit);
                    bitCount[bit]--;
                }
            }

            // Add square modulo MOD.
            ans = (ans + curr * curr % MOD) % MOD;
        }

        return (int)ans;
    }
};