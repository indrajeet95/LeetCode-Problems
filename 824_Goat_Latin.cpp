class Solution {
public:
    // .i = 2 j = 7
    string toGoatLatin(string S) {
        string res;
        unordered_set<char> vowels = {'a','e','i','o','u','A','E','I','O','U'};
        int count = 1;
        for(int i=0; i< S.size(); i++)
        {
            string temp(count,'a');
            if(S[i] != ' ')
            {
                int j = i;
                for(; j< S.size() && S[j] != ' '; j++) {}
                if(vowels.find(S[i]) == vowels.end())
                {
                    res = res + S.substr(i+1,j-i-1) + S[i] + "ma" + temp + " ";
                }
                else
                {
                    cout << res << endl;
                    res = res + S.substr(i,j-i) + "ma" + temp + " ";
                    cout << res << endl;
                }
                i = j;
            }
            count++;
        }
        res.pop_back();
        return res;
    }
};