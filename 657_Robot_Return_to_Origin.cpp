class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0, y = 0;
        unordered_map<char, pair<int,int>> direction;
        direction['L'] = make_pair(0,-1);
        direction['R'] = make_pair(0, 1);
        direction['U'] = make_pair(1, 0);
        direction['D'] = make_pair(-1, 0);
        for(auto s : moves)
        {
            x += direction[s].first;
            y += direction[s].second;
        }
        if(x == 0 && y == 0)
            return true;
        else
            return false;
    }
};