class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> s;
        s.push(0);
        for(int i=0;i<S.size();i++)
        {
            if(S[i] == '(')
                s.push(0);
            else
            {
                int top = s.top();
                s.pop();
                int top2 = s.top();
                s.pop();
                s.push(top2 + max(2*top,1));
            }
        }
        return s.top();
    }
};
