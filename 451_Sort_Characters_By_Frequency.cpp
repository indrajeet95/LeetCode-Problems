class Solution {
public:
    string frequencySort(string s) {
    unordered_map<char, int> m1;
    priority_queue<pair<int, char>> q1;
    for (int i = 0;i<s.length();i++)
	    m1[s[i]]++;
    for (auto it = m1.begin();it != m1.end();it++)
	    q1.push(make_pair(it->second, it->first));
    string res = "";
    while (q1.size()) {
    	pair<int , char> y1 = q1.top();
    	for(int i=0;i<q1.top().first;i++)
    	    res += q1.top().second;
    	q1.pop();
    }
    return res;
    }
};
