class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        int first;
        int second;
        stack<int> st;
        int tokensSize = tokens.size();

        for (int i = 0; i < tokensSize; i++) {

            if (tokens[i] != "*" && tokens[i] != "/" && tokens[i] != "+" &&
                tokens[i] != "-") {

                st.push(stoi(tokens[i]));

            } else {
                if (st.size() >= 2) {
                    first = st.top();
                    st.pop();
                    second = st.top();
                    st.pop();

                    if (tokens[i] == "/") {

                        st.push(second / first);
                    } else if (tokens[i] == "-") {

                        st.push(second - first);
                    } else {

                        if (tokens[i] == "*") {

                            st.push(second * first);
                        } else {

                            st.push(second + first);
                        }
                    }
                }
            }
        }

        return st.top();
    }
};
