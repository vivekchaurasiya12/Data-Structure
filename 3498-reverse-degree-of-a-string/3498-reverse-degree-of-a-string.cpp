class Solution {
public:
    int reverseDegree(string s) {
        
         int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            int reversedPos = 26 - (s[i] - 'a');
            int stringPos = i + 1;

            ans += reversedPos * stringPos;
        }

        return ans;
    }
};