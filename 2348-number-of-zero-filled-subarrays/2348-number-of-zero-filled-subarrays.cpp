class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long current =0;
        long long ans = 0;
        for(int num:nums){
            if(num==0){
                current++;
            }else{
                current=0;
            }
            ans +=current;
        }
        return ans;
        
    }
};