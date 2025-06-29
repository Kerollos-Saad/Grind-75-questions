class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for(auto&it:tokens)
        {
            if (it != "+" && it != "-" && it != "*" && it != "/") {
                st.push(stoi(it));
            } else {
                int right = st.top(); st.pop();
                int left = st.top(); st.pop();
                
                if (it == "+") st.push( left + right );
                if (it ==  "-") st.push( left - right );
                if (it ==  "*") st.push( left * right );
                if (it ==  "/") st.push( left / right );
            }
        }
        return st.top();
    }
};