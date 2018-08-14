class Solution {
public:
    string reverseWords(string s) {
        string res;
        vector<string> words;
        int count = 1;
        int start = 0;
        for(int i=1; i<s.size(); i++)
        {
            if(s[i] == ' ')
            {
                //cout << s.substr(start,i-start);
                words.push_back(s.substr(start,i-start));
                start = i+1;
            }
        }
        words.push_back(s.substr(start,s.size()-start));
        for(int i=0;i<words.size();i++)
        {
            reverse(words[i].begin(),words[i].end());
            if(i == words.size() - 1)
                res += words[i];
            else
                res += words[i] + ' ';
        }
        cout << res;
        return res;
    }   
};