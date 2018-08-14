class Solution {
public:
    string reverseStr(string s, int k) {
        int len = s.length();
        for (int i = 0; i < len; i += 2 * k) {
            int end = min(len, i+k);
            reverse(s.begin() + i, s.begin() + end);
        }
        return s;
    }
};