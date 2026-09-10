class Solution {
public:
    int findMaxLength(vector<int>& nums) {
       unordered_map<int,int> prefixIndex;
       prefixIndex[0]=-1;
       int currentPrefixSum = 0;
       int maxLength = 0;

       for(int index = 0;index<nums.size();index++){
            if(nums[index]==0){
                currentPrefixSum+=-1;
            }else{
                currentPrefixSum +=1;
            }

            if(prefixIndex.count(currentPrefixSum)){
                int lastindex = prefixIndex[currentPrefixSum];
                maxLength = max(maxLength,index-lastindex);
            }else{
                prefixIndex[currentPrefixSum]=index;
            }
       }
       return maxLength;


        
    }
};