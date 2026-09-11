class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int,int> prefixfreq;
        prefixfreq[0]=1;
        int count =0;
        int currentprefixsum = 0;
        for(int i=0;i<nums.size();i++){
            currentprefixsum+=nums[i];

            int targetprefixsum = currentprefixsum - goal;
            if(prefixfreq.count(targetprefixsum)){
                count+=prefixfreq[targetprefixsum];
            }
            prefixfreq[currentprefixsum]++;
        }
        return count;
        
    }
};