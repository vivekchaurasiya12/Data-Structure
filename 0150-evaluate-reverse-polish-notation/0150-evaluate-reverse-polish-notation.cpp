class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int>st;

        for(auto token : tokens){
            if(token !="-" && token !="+" && token!="/" && token !="*"){
                st.push(stoi(token));
            }else{
                int num1 = st.top();
                st.pop();

                int num2 = st.top();
                st.pop();

                if(token=="+"){
                    st.push(num2+ num1);
                }else if(token=="-"){
                    st.push(num2-num1);
                }else if(token=="*"){
                    st.push(num2*num1);
                }else{
                    st.push(num2/num1);
                }


            }

        }
        return st.top();
        
    }
};