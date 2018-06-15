class Solution {
public:
    bool isValid(string s) {
    int len = s.length();
    stack<char> S;
    for(int i=0;i<len;i++)
    {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            S.push(s[i]);
        else if(s.at(i) == ')')
        {
            if(S.empty())
                return false;
            else
            {
                char c = S.top();
                S.pop();
                if (c != '(')
                    return false;
            }
        }
        else if(s.at(i) == '}')
        {
            if(S.empty())
                return false;
            else
            {
                char c = S.top();
                S.pop();
                if (c!='{')
                    return false;
            }
        }
        else if(s.at(i) == ']')
        {
            if(S.empty())
                return false;
            else
            {
                char c = S.top();
                S.pop();
                if (c!='[')
                    return false;
            }
        }
    }
    return S.empty();
    }
};
