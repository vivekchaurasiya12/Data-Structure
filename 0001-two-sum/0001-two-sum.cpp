class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
      unordered_map<int,int> mpp;
     for(int i=0;i<nums.size();i++){
         
         int required = target - nums[i];
         if(mpp.count(required)){
            return {mpp[required],i};
         }else{
            mpp[nums[i]] = i;
         }


     }
     return {};   
    }
};