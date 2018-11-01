class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> maps(26);
        for(int i=0; i<s.size(); i++)
            maps[s[i]]++;
        for(int i=0; i<s.size(); i++)
        {
            if(maps[s[i]] == 1)
                return i;
        }
        return -1;
    }
};