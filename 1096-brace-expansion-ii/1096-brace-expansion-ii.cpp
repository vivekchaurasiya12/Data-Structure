class Solution {
public:
     set<string> parse(string& s, int& i) {
        set<string> result;

        while (i < s.size() && s[i] != '}') {
            set<string> cur;

            if (s[i] == '{') {
                i++; // skip '{'
                cur = parse(s, i);
                i++; // skip '}'
            } 
            else {
                cur.insert(string(1, s[i]));
                i++;
            }

            // Concatenate current result with cur
            if (result.empty()) {
                result = cur;
            } else {
                set<string> temp;

                for (const string& a : result) {
                    for (const string& b : cur) {
                        temp.insert(a + b);
                    }
                }

                result = temp;
            }

            // If comma, the current expression ends here.
            if (i < s.size() && s[i] == ',') {
                i++;
                
                set<string> next = parse(s, i);
                
                result.insert(next.begin(), next.end());
                return result;
            }
        }

        return result;
    }

    vector<string> braceExpansionII(string expression) {
        int i = 0;

        set<string> result = parse(expression, i);

        return vector<string>(result.begin(), result.end());
    }
};