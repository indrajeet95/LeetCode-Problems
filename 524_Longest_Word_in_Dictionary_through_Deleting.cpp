class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        int len = s.length();
        map<string,int> maps;
        for(int i=0;i<d.size();i++)
        {
            if(d[i].length()<=len)
                maps[d[i]] = d[i].length();
        }
        int max = 0;
        string res;
        for(auto it = maps.begin();it!=maps.end();it++)
        {
            int i=0,j=0;
            bool possible = false;
            while(i < s.length() && j < (it->first).length())
            {
                while(s[i] != it->first[j])
                    i++;
                if(s[i] == it->first[j])
                {
                    i++;
                    j++;
                }
            }
            if(j == (it->first).length())
                possible = true;
            if(max < it->first.length() && possible)
            {
                max = it->first.length();
                cout << it->first<<endl;
                res = it->first;
            }
        }
        return res;
    }
};