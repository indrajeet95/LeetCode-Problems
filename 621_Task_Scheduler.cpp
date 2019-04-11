class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> map(26,0);
        for(auto ch : tasks)
            map[ch - 'A']++;
        sort(map.begin(), map.end());
        int res = 0;
        while(map[25] > 0) {
            int i = 0;
            while(i <= n) {
                if(map[25] == 0)
                    break;
                if(i < 26 && map[25 - i] > 0)
                    map[25 - i]--;
                res++;
                i++;
            }
            sort(map.begin(), map.end());
        }
        return res;
    }
};
