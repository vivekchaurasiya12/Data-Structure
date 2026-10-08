class Solution {
public:
    string removeOuterParentheses(string s) {
         string result = "";
        int balance = 0;

        for (char ch : s) {

            if (ch == '(') {
                // If balance > 0, this is not the outermost '('
                if (balance > 0) {
                    result += ch;
                }

                balance++;
            }
            else {
                balance--;

                // If balance > 0, this is not the outermost ')'
                if (balance > 0) {
                    result += ch;
                }
            }
        }

        return result;
    }
};