class Solution {
public:
//thodi ai ki help
    int evalRPN(vector<string>& tokens) {
        std::stack<int> st;

        for(const std::string & token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int rightOperand = st.top();
                st.pop();
                int leftOperand = st.top();
                st.pop();
        
                if (token == "+") {
                    st.push(leftOperand + rightOperand);
                }
                else if (token == "-") {
                    st.push(leftOperand - rightOperand);
                }
                else if (token == "*") {
                    st.push(leftOperand * rightOperand);
                }
                else if (token == "/") {
                    st.push(leftOperand / rightOperand);
                }
            }
            else {
                st.push(std::stoi(token));
            }
        }
        return st.top();
    }
};