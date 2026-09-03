class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        
        vector<int> pattern(26,0);
        int k = p.size();

        if(k>s.size()) return {};
        for(char ch:p){
            pattern[ch-'a']++;
        }

        vector<int> window(26,0);
        vector<int> answer;
        for(int i=0;i<k;i++){
            window[s[i]-'a']++;
        }
        if(window==pattern){
            answer.push_back(0);

        }

        for(int i=k;i<s.size();i++){
            window[s[i]-'a']++;
            window[s[i-k]-'a']--;

            if(window==pattern){
                answer.push_back(i-k+1);
            }
        }

        return answer;
        
    }
};
