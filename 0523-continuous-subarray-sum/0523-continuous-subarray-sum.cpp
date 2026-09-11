class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
          unordered_map<int,int> remainderFreq;

          remainderFreq[0]=-1;
          long long currentPrefixSum=0;
          int len = 0;
          for(int i=0;i<nums.size();i++){
            currentPrefixSum+=nums[i];

            int remainder  = (((currentPrefixSum%k)+k)%k);
            if(remainderFreq.count(remainder)){
                len = i-remainderFreq[remainder];
                if(len>=2){
                    return true;
                }
            }else{
               remainderFreq[remainder]=i;
            }

           
          }

          return false;

        
    }
};