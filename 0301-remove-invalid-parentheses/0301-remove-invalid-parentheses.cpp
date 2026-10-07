class Solution {
public:
    unordered_set<string> ans;

    void backtrack(string &s, int index,
                   int leftCount, int rightCount,
                   int leftRemove, int rightRemove,
                   string current) {

        // We have processed the entire string
        if (index == s.length()) {
            // All required removals must be used
            if (leftRemove == 0 && rightRemove == 0) {
                ans.insert(current);
            }
            return;
        }

        char ch = s[index];

        // Option 1: Remove current '('
        if (ch == '(' && leftRemove > 0) {
            backtrack(s, index + 1,
                      leftCount, rightCount,
                      leftRemove - 1, rightRemove,
                      current);
        }

        // Option 2: Remove current ')'
        if (ch == ')' && rightRemove > 0) {
            backtrack(s, index + 1,
                      leftCount, rightCount,
                      leftRemove, rightRemove - 1,
                      current);
        }

        // Option 3: Keep current character
        if (ch == '(') {
            // '(' is always safe to keep
            backtrack(s, index + 1,
                      leftCount + 1, rightCount,
                      leftRemove, rightRemove,
                      current + ch);
        }
        else if (ch == ')') {
            // ')' can be kept only if we have an unmatched '('
            if (leftCount > rightCount) {
                backtrack(s, index + 1,
                          leftCount, rightCount + 1,
                          leftRemove, rightRemove,
                          current + ch);
            }
        }
        else {
            // Letters are always valid
            backtrack(s, index + 1,
                      leftCount, rightCount,
                      leftRemove, rightRemove,
                      current + ch);
        }
    }

    vector<string> removeInvalidParentheses(string s) {
        int leftRemove = 0;
        int rightRemove = 0;

        // Find the minimum number of invalid parentheses
        for (char ch : s) {
            if (ch == '(') {
                leftRemove++;
            }
            else if (ch == ')') {
                if (leftRemove > 0) {
                    leftRemove--;
                }
                else {
                    rightRemove++;
                }
            }
        }

        // Generate all valid strings with minimum removals
        backtrack(s, 0, 0, 0,
                  leftRemove, rightRemove, "");

        return vector<string>(ans.begin(), ans.end());
    }
};