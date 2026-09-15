class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currentmaxproduct = nums[0];
        int currentminproduct = nums[0];

        int maxproduct = nums[0];

        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(currentmaxproduct,currentminproduct);
            }

            currentmaxproduct = max(nums[i],currentmaxproduct*nums[i]);
            currentminproduct = min(nums[i],currentminproduct * nums[i]);

            maxproduct = max(maxproduct,currentmaxproduct);
        }
        return maxproduct;
        
    }
};