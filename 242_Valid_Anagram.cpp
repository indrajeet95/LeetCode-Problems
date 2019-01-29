class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if(s == t)
            return true;
        else
            return false;
        
    }
};

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size())
            return false;
        int n = s.size();
        unordered_map<char, int> map;
        for(int i=0; i<n; i++)
        {
            map[s[i]]++;
            map[t[i]]--;
        }
        for(auto vals : map)
        {
            if(vals.second)
                return false;
        }
        return true;
    }
};