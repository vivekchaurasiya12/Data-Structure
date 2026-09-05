class Solution {
public:
    string minWindow(string s, string t) {
         unordered_map<char,int> need;
         unordered_map<char,int> window;
         for(char c:t){
            need[c]++;
         }
         if(t.size()>s.size()) return "";

         int left =0;
         int formed = 0;
         int required = need.size();
         int minlen = INT_MAX;
         int start = 0;

         for(int right=0;right<s.size();right++){
              char c = s[right];

              if(need.count(c)){
                window[c]++;
                 if(window[c]==need[c]){
                    formed++;
                 }
              }

              while(formed==required){
                int len = right-left+1;
                if(len<minlen){
                    minlen = len;
                    start = left;
                }

                 char leftchar = s[left];

                 if(need.count(leftchar)){
                    window[leftchar]--;

                    if(window[leftchar]<need[leftchar]){
                        formed--;
                    }
                 }
                 left++;
              }
         }

         if(minlen == INT_MAX){
            return "";
         }
         return s.substr(start,minlen);

    }
};