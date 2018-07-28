class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_map<int,int> maps;
        for(int i=0;i<candies.size();i++)
            maps[candies[i]] += 1;
        int res = 0;
        int total = (candies.size())/2;
        for(auto x : maps)
        {
            if(x.second>0)
                res++;
            if(res == total)
                break;
        }
        return res;
    }
};
