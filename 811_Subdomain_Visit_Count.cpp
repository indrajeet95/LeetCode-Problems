class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> maps;
        for(auto it=cpdomains.begin();it != cpdomains.end(); it++)
        {
            string temp = *it;
            int found = temp.find(" ");
            int visit = stoi(temp.substr(0,found));
            string temp1 = temp.substr(found+1,temp.size()-found-1);
            for(int i=0;i<temp1.size();i++)
            {
                if(temp1[i] == '.')
                    maps[temp1.substr(i+1,temp1.size()-i)] += visit;
            }
            maps[temp1] += visit;
        }
        vector<string> res;
        for(auto it = maps.begin(); it!=maps.end();it++)
            res.push_back(to_string(it->second)+" "+it->first);
        return res;
    }
};
