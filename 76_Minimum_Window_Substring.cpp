class Solution {
public:
    string minWindow(string s, string t) {
        string res;
        int min = INT_MAX;
        unordered_map<char,int> map;
        unordered_map<char,int> window;
        for(int i=0;i<t.size();i++)
            map[t[i]]++;
//        for(auto it=map.begin();it!=map.end();it++)
//            cout << it->first << " "<< it->second << endl;
        for(int i=0,j=0;j<s.size();j++)
        {
            cout << i << " " << j<< " " << window.size()<<endl;
            if(map.find(s[j]) != map.end())
                window[s[j]]++;
            if(window.size() >= t.size())
            {
                while((map.find(s[i]) == map.end()) || window[s[i]] > map[s[i]])
                {
                    window[s[i]]--;
                    i++;
                }
//                if(map.find(s[i]) != map.end())
//                    cout << s[i];
                if(j-i+1<min)
                {
                    min = j-i+1;
                    res = s.substr(i,min);
                }
            }
        }
        return res;
    }
};
/*
string minWindow(string S, string T) {
    string result;
    if(S.empty() || T.empty()){
        return result;
    }
    unordered_map<char, int> map;
    unordered_map<char, int> window;
    for(int i = 0; i < T.length(); i++){
        map[T[i]]++;
    }
    int minLength = INT_MAX;
    int letterCounter = 0;
    for(int slow = 0, fast = 0; fast < S.length(); fast++){
        char c = S[fast];
        if(map.find(c) != map.end()){
            window[c]++;
            if(window[c] <= map[c]){
                letterCounter++;
            }
        }
        if(letterCounter >= T.length()){
            while(map.find(S[slow]) == map.end() || window[S[slow]] > map[S[slow]]){
                window[S[slow]]--;
                slow++;
            }
            if(fast - slow + 1 < minLength){
                minLength = fast - slow + 1;
                result = S.substr(slow, minLength);
            }
        }
    }
    return result;
}