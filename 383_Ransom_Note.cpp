class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        bool res = true;
        for(int i=0; i<ransomNote.size(); i++)
        {
            if(magazine.find(ransomNote[i]) == string::npos)
                return false;
            else
                magazine.erase(magazine.find(ransomNote[i]),1);
        }
        return res;
    }
};

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> map(26);
        for (int i = 0; i < magazine.size(); ++i)
            ++map[magazine[i]];
        for (int j = 0; j < ransomNote.size(); ++j)
            if (--map[ransomNote[j]] < 0)
                return false;
        return true;
    }
};