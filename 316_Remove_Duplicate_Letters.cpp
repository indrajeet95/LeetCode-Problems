
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<bool> visited(26, 0);
        vector<int> count(26, 0);
        stack<int> st;          
        string ans;      
        
        for (auto c: s)
            count[c-'a']++;
        
        for (auto c : s) {
            int idx = c - 'a';
            count[idx]--;
            if(visited[idx])
                continue;
            while(!st.empty() && count[st.top()] && st.top() > idx) {
                visited[st.top()] = false;
                st.pop();
            }
            st.push(idx);
            visited[idx] = true;
        }
        
        while(!st.empty()) {
            ans = string(1, 'a'+st.top()) + ans;
            st.pop();
        }
        return ans;
    }
};