class Solution {
public:
    bool checkRecord(string s) {
        unordered_map<char,int> maps(3);
        for(int i=0; i<s.size(); i++)
            maps[s[i]]++;
//        string regex = "LLL";
//        smatch sm;
//        regex_match(s,sm,regex);
        if(maps['A']>1 || (s.find("LLL") != string::npos))
            return false;
        else
            return true;
    }
};