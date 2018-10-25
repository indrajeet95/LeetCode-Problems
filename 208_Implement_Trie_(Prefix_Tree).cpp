class TrieNode {
    public:
    bool isWord;
    TrieNode* next[26];
    
    TrieNode() {
        isWord = false;
        for(int i=0; i<26; i++)
            next[i] = NULL;
    }
};

class Trie {
    TrieNode* root;
    public:
    Trie() {
        root = new TrieNode();
    }
    void insert(string s)
    {
        TrieNode* p = root;
        for(int i=0;i<s.size();i++)
        {
            if(p->next[s[i] - 'a'] == NULL)
                p->next[s[i] - 'a'] = new TrieNode();    
            p = p->next[s[i] - 'a'];
        }
        p->isWord = true;
    }
    
    bool search(string s)
    {
        TrieNode* temp = contains(s);
        return temp!=NULL && temp->isWord == true;
    }
    
    bool startsWith(string s)
    {
        TrieNode* temp = contains(s);
        return temp!=NULL;
    }
    
    private:
    TrieNode* contains(string s)
    {
        TrieNode* p = root;
        for(int i=0;i<s.size() && p!=NULL;i++)
            p = p->next[s[i] - 'a'];
        return p;
    }
};