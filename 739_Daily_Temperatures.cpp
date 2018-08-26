class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> m(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++)
        {
            int j = i;
            while(!s.empty() && temperatures[s.top()] < temperatures[j])
            {
                m[s.top()] = j - s.top();
                s.pop();
            }
            s.push(i);
        }
        return m;
    }
};