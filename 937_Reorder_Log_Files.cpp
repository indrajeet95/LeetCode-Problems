class Solution {
private:
    bool static Compare(const pair<string,string> a, const pair<string,string> b) 
    { 
    return (a.second < b.second); 
    } 
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<pair<string, string>> holders;
        for(auto str: logs) {
            int index = str.find(' ');
            string first = str.substr(0, index);
            string second = str.substr(index);
            holders.push_back(make_pair(first, second));
        }
        vector<string> letter_logs;
        vector<pair<string, string>> letters;
        vector<string> digit_logs;
        for(auto pair : holders) {
            int flag = 0;
            for(auto ch : pair.second) {
                if((ch >= 'a' && ch <= 'z') || ch == ' ')
                    flag = 1;
                else if((ch >= '0' && ch <= '9') || ch == ' ')
                    flag = 2;
            }
            if(flag == 1) {
                letters.push_back(make_pair(pair.first, pair.second));
                letter_logs.push_back(pair.first + pair.second);
            }
            else if(flag == 2)
                digit_logs.push_back(pair.first + pair.second);
        }
        sort(letters.begin(), letters.end(), Compare);
        cout << "LETTER LOGS:" << endl;
        for(auto a : letter_logs)
            cout << a << " ";
        cout << endl;
        cout << "DIGIT LOGS:" << endl;
        for(auto a : digit_logs)
            cout << a << " ";
        cout << endl;
        vector<string> res;
        for(auto pair : letters)
            res.push_back(pair.first + pair.second);
        for(auto str: digit_logs)
            res.push_back(str);
        return res;
    }
};
