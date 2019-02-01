class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> res;
        for(auto no : A)
            res.push_back(pow(no,2));
        sort(res.begin(), res.end());
        return res;
    }
};