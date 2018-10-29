class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> dict = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> ans;
        for(auto word: words)
        {
            string code = "";
            for(auto ch : word)
            {
                code += dict[ch - 'a'];
            }
            ans.insert(code);
        }
        return ans.size();
    }
};