class Solution {
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        int lasttime = 0;
        stack<int> st;
        vector<int> res(n,0);
        int pos = 0;
        for(int i=0;i<logs.size();i++)
        {
            string str = logs[i];
            pos = str.find(":");
            int func = stoi(str.substr(0,pos));
            str.erase(0,pos+1);
            pos = str.find(":");
            string idt = str.substr(0,pos);
            str.erase(0,pos+1);
            int curtime = stoi(str);
            if(idt == "start")
            {
                if(!st.empty())
                    res[st.top()] += curtime - lasttime;
                st.push(func);
                lasttime = curtime;
            }
            else
            {
                res[st.top()] += curtime - lasttime + 1;
                st.pop();
                lasttime = curtime + 1;
            }
        }
        return res;
    }
};
