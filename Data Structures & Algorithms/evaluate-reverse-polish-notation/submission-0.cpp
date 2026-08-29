class Solution {
   public:
    int evalRPN(vector<string>& srins) {
        stack<int> st;

        for (string& srin : srins) {
            if (srin == "+" || srin == "-" || srin == "*" || srin == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                int result = 0;
                if (srin == "+") {
                    result = a + b;
                } else if (srin == "-") {
                    result = a - b;
                } else if (srin == "*") {
                    result = a * b;
                } else if (srin == "/") {
                    result = a / b;
                }

                st.push(result);
            } else {
                st.push(stoi(srin));
            }
        }

        return st.top();
    }
};
