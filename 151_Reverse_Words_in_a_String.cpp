class Solution {
public:
    void reverseWords(string &s) {
        stack<string> st;
        istringstream ss(s);
        string word;
        while(ss >> word)
            st.push(word);
        s = "";
        while(st.size() != 0)
        {
            s += st.top() + " ";
            st.pop();
        }
        s.pop_back();
    }
};

class Solution {
public:
    void reverseWords(string &s) {
        reverse(s.begin(),s.end());
        auto i = s.begin(), j = i;
        while(i != s.end())
        {
            if(*i != ' ')
            {
                j = i+1;
                while(*j != ' ' && j != s.end())
                    j++;
                reverse(i,j);
                i = j;
                if(i == s.end() || ++i == s.end())
                    break;
            }
            else
                i = s.erase(i);
        }
        if(*(s.rbegin()) == ' ')
            s.pop_back();
    }
};
/*
void reverseWords(string &s) {
      reverse(s.begin(), s.end());
      auto i = s.begin(), j = i;
      while (i != s.end()) {
        if (*i != ' ') {
          for (j = i + 1; j != s.end() && *j != ' '; j++); 
          reverse(i, j); i = j; 
          if (i == s.end() || ++i == s.end()) break;
        }
        else i = s.erase(i);
      }
      if (*(s.rbegin()) == ' ') s.pop_back();
    }
