class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_map<string,int> words;
        unordered_map<string,int> bans;
        for(int i=0;i<banned.size();i++)
            bans[banned[i]]++;
        for (auto & c: paragraph) c = isalpha(c) ? tolower(c) : ' ';
        stringstream ss(paragraph);
        string word;
        while(ss >> word)
            words[word]++;
        int max = 0;
        string res;
        for(auto it= words.begin(); it!=words.end(); it++)
            cout << it->first << " : " << it->second << endl;

        for(auto it= words.begin(); it!=words.end(); it++)
        {
            if(bans.find(it->first) == bans.end() && max < it->second)
            {
                res = it->first;
                max = it->second;
            }    
            
        }
        return res;
    }
};