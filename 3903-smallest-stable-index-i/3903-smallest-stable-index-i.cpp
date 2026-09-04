class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         

        vector<int> prefixMax(nums.size());
        vector<int> suffixMin(nums.size());

        // Prefix maximum
        prefixMax[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            prefixMax[i] = max(prefixMax[i - 1], nums[i]);
        }

        // Suffix minimum
        suffixMin[nums.size() - 1] = nums[nums.size() - 1];

        for (int i = nums.size() - 2; i >= 0; i--) {
            suffixMin[i] = min(suffixMin[i + 1], nums[i]);
        }

       
        for (int i = 0; i < nums.size(); i++) {
            int instability = prefixMax[i] - suffixMin[i];

            if (instability <= k) {
                return i;
            }
        }

        return -1;
    }
};