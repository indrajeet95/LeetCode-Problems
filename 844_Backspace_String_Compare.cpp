class Solution {
public:
    bool backspaceCompare(string S, string T) {
        stack<char> A;
        stack<char> B;
        vector<char> resA;
        vector<char> resB;
        for(int i=0;i<S.length();i++)
        {
            if(S[i] == '#')
            {
                if(!A.empty())
                    A.pop();
            }
            else
            {
                cout <<S[i];
                A.push(S[i]);
            }
        }
        for(int i=0;i<T.length();i++)
        {
            if(T[i] == '#')
            {
                if(!B.empty())
                    B.pop();
            }
            else
            {
                cout <<T[i];
                B.push(T[i]);
            }
        }
        while(!A.empty())
        {
            resA.push_back(A.top());
            A.pop();        
        }
        while(!B.empty())
        {
            resB.push_back(B.top());
            B.pop();        
        }
        if(resA == resB)
            return true;
        else
            return false;
    }
};