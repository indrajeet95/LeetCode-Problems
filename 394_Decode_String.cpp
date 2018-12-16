class Solution {
public:
    string decodeString(string s) {
        string res;
        stack<string> chars;
        stack<int> nums;
        int num = 0;
        for(auto ch : s)
        {
            if(isalpha(ch))
                res.push_back(ch);
            else if(isdigit(ch))
            {
                num = num*10 + ch - '0';
            }
            else if(ch == '[')
            {
                chars.push(res);
                nums.push(num);
                res = "";
                num = 0;
            }
            else if(ch == ']')
            {
                string tmp = res;
                for(int i=0; i<nums.top()-1; i++)
                    res += tmp;
                res = chars.top() + res;
                nums.pop();
                chars.pop();
            }
        }
        return res;
    }
};