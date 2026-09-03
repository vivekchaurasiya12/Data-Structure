class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        
        int n = nums.size();
        long long windowsum = 0;
        unordered_map<int,int> distinctFreq;

        for(int i=0;i<k;i++){
            windowsum+=nums[i];
            distinctFreq[nums[i]]++; 
        }
        long long maxsum = 0;
        if(distinctFreq.size()==k){
          maxsum = windowsum;
        }

        for(int i=k;i<n;i++){
            windowsum+=nums[i]-nums[i-k];
            distinctFreq[nums[i]]++;
            distinctFreq[nums[i-k]]--;
            if(distinctFreq[nums[i-k]]==0){
                distinctFreq.erase(nums[i-k]);
            }
            if(distinctFreq.size()==k){
                maxsum = max(maxsum,windowsum);
            }
        }
        return maxsum;


        


        
        
    }
};