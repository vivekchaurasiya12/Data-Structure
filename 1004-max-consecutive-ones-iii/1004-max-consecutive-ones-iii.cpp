class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ans = 0;
        long long count =0;
        int left = 0;

        for(int right=0;right<nums.size();right++){
            if(nums[right]==1){
                count++;
            }

            while(((right-left+1)-count)>k){
                if(nums[left]==1){
                    count--;
                }
                left++;
            }

            ans = max(ans,right-left+1);
        }
        return ans;
        
    }
};