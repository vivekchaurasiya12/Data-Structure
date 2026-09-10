class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> prefixFreq;
        prefixFreq[0]=1;
        int currentPrefixSum = 0;
        int count = 0;

        for(int num:nums){
            currentPrefixSum+=num;

            int targetPrefixSum = currentPrefixSum -k;
            if(prefixFreq.count(targetPrefixSum)){
                count+=prefixFreq[targetPrefixSum];
            }

            prefixFreq[currentPrefixSum]++;
        }

        return count;

        
    }
};