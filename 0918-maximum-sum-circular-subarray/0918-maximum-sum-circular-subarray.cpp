class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        int currentmaxsum = nums[0];
        int currentminsum = nums[0];
        
        int maxsubarraysum = nums[0];
        int minsubarraysum = nums[0];
        int totalsum = nums[0];

        for(int i=1;i<nums.size();i++){
            totalsum +=nums[i];

            currentmaxsum = max(nums[i],currentmaxsum+nums[i]);
            maxsubarraysum = max(maxsubarraysum,currentmaxsum);

            currentminsum = min(nums[i],currentminsum+nums[i]);
            minsubarraysum = min(minsubarraysum,currentminsum);

        }
        if(maxsubarraysum<0){
            return maxsubarraysum;
        }

        return max(maxsubarraysum,totalsum-minsubarraysum);
        
    }
};