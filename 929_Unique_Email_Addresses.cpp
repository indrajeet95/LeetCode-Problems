class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> res;
        for(auto it = emails.begin(); it != emails.end(); it++)
        {
            string holder = *it; 
            auto foundat = holder.find('@');
            string local = holder.substr(0, foundat);
            string domain = holder.substr(foundat);
            if(local.find('+') != string::npos)
            {
                auto foundplus = holder.find('+');
                local = local.substr(0, foundplus);
            }
            for(int i=0; i<local.size(); i++)
            {
                if(local[i] == '.')
                    local.erase(local.begin() + i);
            }
            holder = local + '@' + domain;
            res.insert(holder);
        }
        return res.size();
        
    }
};