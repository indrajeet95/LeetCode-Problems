//best way to complicate solutions you shall learn from me

class Solution {
public:
    vector<string> words(string s)
    {
        vector<string> temp;
        int start = 0;
        for(int i = 0;i<s.size();i++)
        {
            if(s[i] == ' ')
            {
                temp.push_back(s.substr(start,i -start));          
                start = i+1;              
            }
        }
        temp.push_back(s.substr(start,s.size()-start));
        return temp;
    }
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> result;
        unordered_map<string,int> maps;
        vector<string> resa = words(A);
        vector<string> resb = words(B);
        for(auto it=resa.begin();it!=resa.end();it++)            
        {
            maps[*it]++;
            cout << *it;
        }
        for(auto it=resb.begin();it!=resb.end();it++)
        {
            maps[*it]++;
            cout << *it;
        }
        for(auto it=maps.begin();it!=maps.end();it++)
        {
            if(it->second == 1)
                result.push_back(it->first);
        }
        return result;
    }
};

class Solution {
public:
    vector<string> uncommonFromSentences(string A, string B) {
        vector<string> res;
        unordered_map<string,int> maps;
        istringstream is(A + " " + B);
        string word;
        while(is >> word)
            maps[word]++;
        for(auto it=maps.begin();it!=maps.end();it++)
            if(it->second == 1)
                res.push_back(it->first);
        return res;
    }
};