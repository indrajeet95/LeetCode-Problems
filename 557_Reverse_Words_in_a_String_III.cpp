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

class Solution {
public:
    string reverseWords(string s) {
        string res;
        vector<string> rwords;
        string temp = "";
        for(auto ch: s)
        {
            if(ch != ' ')
                temp += ch;
            else
            {
                reverse(temp.begin(),temp.end());
                rwords.push_back(temp);
                temp = "";
            }
        }
        reverse(temp.begin(), temp.end());
        rwords.push_back(temp);
        for(auto word : rwords)
            res = res + word + " ";
        res.pop_back();
        return res;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] != ' ')
            {
                int j = i;
                for(; j<s.size() && s[j] != ' '; j++) { }
                reverse(s.begin() + i, s.begin() + j);
                i = j;
            }
//            i = j;
        }
        return s;
    }
};

//L e t ' s   t a k e
//0 1 2 3 4 5 6 7 8 9 10