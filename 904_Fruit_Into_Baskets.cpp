class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int,int> maps;
        int unique = 0, res = 0, end = 0, start = 0;
        while(end < tree.size())
        {
            maps[tree[end]]++;
            if(maps[tree[end]] == 1)
                unique += 1;
            while(unique>2)
            {
                maps[tree[start]] -= 1;
                if(!maps[tree[start]])
                    unique -= 1;
                start += 1;
            }
            res = max(res, end -start + 1);
            end += 1;
        }
        return res;
    }
};


class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int,int> map;
        int i=0;
        int res = 0;
        for(int j=0; j<tree.size(); j++)
        {
            map[tree[j]]++;
            while(map.size()>2)
            {
                map[tree[i]]--;
                if(map[tree[i]] == 0)
                    map.erase(tree[i]);
                i++;
            }
            res = max(res, j - i + 1); 
        }
        return res;
    }
};