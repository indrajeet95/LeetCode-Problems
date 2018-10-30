class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> ans;
        for(auto word : A)
        {
            string odd = "";
            string even = "";
            for(int i=0; i< word.size(); i++)
            {
                if(i%2 == 0)
                    even += word[i];
                else
                    odd += word[i];
            }
            sort(even.begin(),even.end());
            sort(odd.begin(),odd.end());
            ans.insert(even + odd);
        }
        return ans.size();
        
    }
};