
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int open = 0;
        int insertions = 0;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                // This opening parenthesis needs two ')' characters.
                open++;
            } else {
                // If the next character is not ')',
                // insert one ')' to form a closing pair '))'.
                if (i + 1 < n && s[i + 1] == ')') {
                    i++; // Consume both consecutive closing parentheses.
                } else {
                    insertions++; // Insert the missing ')'.
                }

                // A closing pair must have a matching '('.
                if (open > 0) {
                    open--;
                } else {
                    // No opening parenthesis exists, so insert '('.
                    insertions++;
                }
            }
        }

        // Each unmatched '(' needs two closing parentheses.
        insertions += open * 2;

        return insertions;
    }
};
