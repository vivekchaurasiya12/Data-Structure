class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int currentmaxsum = nums[0];
        int currentminsum = nums[0];

        int maxsum = nums[0];
        int minsum = nums[0];

        for(int i=1;i<nums.size();i++){
            currentmaxsum = max(nums[i],currentmaxsum+nums[i]);
            maxsum = max(maxsum,currentmaxsum);

            currentminsum = min(nums[i],currentminsum+nums[i]);
            minsum = min(minsum,currentminsum);

        }
        return max(maxsum,abs(minsum));
        
    }
};