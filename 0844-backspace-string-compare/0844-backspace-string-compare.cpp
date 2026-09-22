class Solution {
public:

    int build(string &s){
        int k= 0;

        for(int i=0;i<s.size();i++){
            if(s[i]=='#'){
                if(k>0){
                    k--;
                }
            }else{
                s[k]=s[i];
                k++;
            }

        }
        return k;
    }
    bool backspaceCompare(string s, string t) {

        int s1 = build(s);
        int t1 = build(t);

        if(s1 !=t1) return false;

        for(int i=0;i<s1;i++){
            if(s[i]!=t[i]){
                return false;
            }
        }
        return true;
        
    }
};