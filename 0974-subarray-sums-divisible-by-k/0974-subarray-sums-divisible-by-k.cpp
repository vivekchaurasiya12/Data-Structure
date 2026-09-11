class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> remainderFreq;
        remainderFreq[0]=1;
        int count = 0;
        int currentPrefixSum = 0;

        for(int i=0;i<nums.size();i++){
            currentPrefixSum += nums[i];
            int remainder = (((currentPrefixSum % k) +k) %k);

            if(remainderFreq.count(remainder)){
                count+=remainderFreq[remainder];
            }

            remainderFreq[remainder]++;

            
        }
        return count;
        
    }
};