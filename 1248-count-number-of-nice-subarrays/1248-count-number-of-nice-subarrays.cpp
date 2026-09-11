class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> prefixfreq;
        prefixfreq[0]=1;
        int count = 0;
        int currentprefixsum = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==1){
              currentprefixsum +=1;
            }else{
                currentprefixsum +=0;
            }

            int targetprefixsum = currentprefixsum - k;

            if(prefixfreq.count(targetprefixsum)){
                count+=prefixfreq[targetprefixsum];
            }
            
            prefixfreq[currentprefixsum]++;
            
        }
        return count;
        
    }
};