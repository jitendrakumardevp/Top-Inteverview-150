class MinStack {
public:
    long mini; 
    stack<long>st; 
    MinStack() {
        
    }
    
    void push(int value) {
        
        if(st.empty())
        {
            st.push(value);
            mini = value;
        }
        else 
        {
            if(value > mini)
                {
                    st.push(value);
                }
            else 
            {
                st.push(2L * value - mini);
                mini = value; 
            }
        }
        
    }
    
    void pop() {
        if(st.empty())
        return ; 

        long x = st.top();
        st.pop();

        if(x < mini)
        {
            mini = 2L * mini - x; 
        }
    }
    
    int top() {
        if(st.empty())
            return NULL; 
        long x = st.top();

        if(mini < x ) return x ; 

        return mini; 
    }
    
    int getMin() {
        return mini; 
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
