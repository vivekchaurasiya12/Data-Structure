#include <bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maximum = 0;

        int left = 0;
        unordered_map<char,int> freqMap;
        for(int right =0;right<s.size();right++){
            freqMap[s[right]]++;

            while(freqMap[s[right]]>1){
                freqMap[s[left]]--;
                left++;
                if(freqMap[s[left]]==0){
                    freqMap.erase(s[left]);
                }
            }
            maximum = max(maximum,right-left+1);
        }

        return maximum;
        
    }
};