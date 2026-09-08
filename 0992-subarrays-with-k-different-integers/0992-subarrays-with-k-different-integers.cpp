class Solution {
public:
     int subarrray(vector<int>& nums,int k){
        unordered_map<int,int> freq;
        int ans = 0;
        int left = 0;
        for(int right =0;right<nums.size();right++){
            freq[nums[right]]++;

            while(freq.size()>k){
                freq[nums[left]]--;
                
                if(freq[nums[left]]==0){
                    freq.erase(nums[left]);
                }
                left++;
               
            }
             ans +=(right-left+1);
        }
        return ans;
     }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans =  subarrray(nums,k)-subarrray(nums,k-1);
        return ans;
        
    }
};