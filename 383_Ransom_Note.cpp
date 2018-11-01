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