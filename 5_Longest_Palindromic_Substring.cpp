//O(n3) solution
//brute force approach
class Solution {
       public:
 
    bool isPalindrome(string s, int i, int j) {
        while(i <= j) {
            if(s[i] != s[j])
                return false;
            else {
                i++;
                j--;
            }
        }
        return true;
    }

    
    string longestPalindrome(string s) {
        string res = "";
        int i = 0;
        if(s.size() == 0)
            return res;
        //if(s.size() == 1)
        //    return s;
        while(i < s.size()) {
            int j = s.size() - 1;
            while(j>=i) {
                if(isPalindrome(s, i, j)) {
                    string candidate = s.substr(i, j - i + 1);
                    cout << "Candidates: " << candidate << endl;
                    if(candidate.size() > res.size())
                        res = candidate;
                }
                j--;
            }
            i++;
        }
        return res;
    }
};
