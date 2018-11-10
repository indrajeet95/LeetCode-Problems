class Solution {
public:
    void reverseWords(string &s) {
        stack<string> st;
        istringstream ss(s);
        string word;
        while(ss >> word)
            st.push(word);
        s = "";
        while(st.size() != 0)
        {
            s += st.top() + " ";
            st.pop();
        }
        s.pop_back();
    }
};