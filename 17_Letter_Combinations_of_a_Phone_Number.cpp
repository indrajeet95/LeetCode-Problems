class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.size() == 0)
            return res;
        res.push_back("");
        map<char,string> map;
        map = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};
        for(int i=0; i<digits.size(); i++)
        {
            string curr = map[digits[i]];
            vector<string> holder;
            for(int j=0; j<curr.size(); j++)
            {
                for(int k=0; k<res.size(); k++)
                {
                    holder.push_back(res[k] + curr[j]);
                }
            }
            res = holder;
            holder.clear();
        }
        return res;
    }
};
