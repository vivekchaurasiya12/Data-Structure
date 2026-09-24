class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        

        for(int num:nums1){
            int k=-1;

            for(int i=0;i<nums2.size();i++){
                if(num == nums2[i]){
                  k=i;
                  break;
                }
            }
            int nextgreater = -1;
           
            for(int j=k+1;j<nums2.size();j++){
                if(nums2[j]>num){
                   nextgreater = nums2[j];
                   break;
                }
                
            }
            
                ans.push_back(nextgreater);
            


        }
        return ans;
    }
};