class TrieNode {
public:
    bool last;
    TrieNode *children[26];
    TrieNode()
    {
        last = false;
        for(int i = 0; i < 26; i++)
        {
            children[i] = nullptr;
        }
    }
};
class Trie{
public:
    TrieNode *root;
    Trie()
    {
        root = new TrieNode();
    }
    void insert(string s)
    {
        TrieNode *curr = root;
        for(int i = 0; i < s.size(); i++)
        {
            int index = s[i] - 'a';
            if(!curr->children[index])
                curr->children[index] = new TrieNode();
            curr = curr->children[index];
        }
        curr->last = true;
    }
    void dfs(TrieNode *curr, string &res, string &s)
    {
        if(curr->last)
        {
            if(s.size() > res.size())
            {
                res = s;
                //displayTrie();
            }
        }
        for(int i = 0; i < 26; i++)
        {
            if(curr->children[i] && curr->children[i]->last)
            {
                s.push_back(i + 'a');
                dfs(curr->children[i], res, s);
                s.pop_back();
            }
        }
    }
    string search()
    {
        string res;
        string s;
        dfs(root, res, s);
        return res;
    }
};
class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie t;
        for(string word: words)
            t.insert(word);
        return t.search();
    }
};