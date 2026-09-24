class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> nextgreater;
        stack<int> st;

        for(int num:nums2){

            while(!st.empty() && num>st.top()){
                nextgreater[st.top()]=num;
                st.pop();
            }
            st.push(num);
        }

        while(!st.empty()){
            nextgreater[st.top()]=-1;
            st.pop();
        }

        vector<int> ans;
        for(int num:nums1){
            ans.push_back(nextgreater[num]);
        }
        return ans;
    }
};