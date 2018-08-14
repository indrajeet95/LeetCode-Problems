class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        vector<int> res;
        int lines = 1;
        int units = 0;
        for(int i=0;i<S.size();i++)
        {
            int x = widths[S[i]- 'a'];
            units += x;
            if(units > 100)
            {
                lines++;
                units = x;
            }
        }
        res.push_back(lines);
        res.push_back(units);
        return res;
    }
};
