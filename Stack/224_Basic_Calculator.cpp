class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int result = 0;
        int sign = 1;
        int n = s.size();
        long num = 0;
        int previousSign;
        int previousResult;

        for (int i = 0; i < n; i++) {
            while (i < n && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            if (i >= n)
                break;

            if (s[i] == '+') {
                result += sign * num;
                num = 0;
                sign = +1;
            } else if (s[i] == '-') {
                result += sign * num;
                sign = -1;
                num = 0;
            } else if (s[i] == ' ') {
                continue;

            } else if (s[i] == '(') {

                st.push(result);
                st.push(sign);
                result = 0;
                sign = 1;
            } else if (s[i] == ')') {
                result += sign * num;
                num = 0;
                previousSign = st.top();
                st.pop();
                previousResult = st.top();
                st.pop();
                result = previousResult + previousSign * result;
            }
        }

        result += sign * num;

        return result;
    }
};
