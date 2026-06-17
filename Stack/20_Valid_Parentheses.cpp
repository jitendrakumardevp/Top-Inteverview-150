class Solution {
public:
    bool isValid(string s) {
       
        stack<char>st;

        for(int i = 0 ; i < s.size(); i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
            }

            if(s[i] == ')' || s[i] == '}' || s[i] == ']')
            {
                if(!st.empty())
                {
                    char ch = st.top();
                    st.pop();

                    if(s[i] == ')' && ch != '(' || s[i] == '}'  &&  ch != '{' || s[i] == ']' && ch != '[')
                    {
                        return false;
                    }
                   
                }
                else 
                {
                    return false;
                }
            }
            
        }

       

        return st.empty();
    }
};
