
https://leetcode.com/problems/min-stack/discuss/49014/Java-accepted-solution-using-one-stack

class MinStack {
public:
    stack<int> st;
    int min = INT_MAX;
    /** initialize your data structure here. */
    MinStack() {}
    
    void push(int x) {
        if(x <= min)
        {
            st.push(min);
            min = x;
        }
        st.push(x);
    }
    
    void pop() {
        if(st.top() == min)
        {
            st.pop();
            min = st.top();
            st.pop();
        }
        else
            st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */