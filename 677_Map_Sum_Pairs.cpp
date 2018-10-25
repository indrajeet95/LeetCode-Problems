class TrieNode {
    public:
    int last;
    TrieNode *next[26];
    TrieNode()
    {
        last = 0;
        for(int i = 0; i < 26; i++)
        {
            next[i] = NULL;
        }
    }
};

class MapSum {
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    MapSum() {
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        TrieNode *curr = root;
        for(int i = 0; i < key.size(); i++)
        {
            if(curr->next[key[i] -'a'] == NULL)
                curr->next[key[i] - 'a'] = new TrieNode;
            curr = curr->next[key[i] -'a'];
        }
        curr->last = val;
    }
    void dfs(TrieNode *curr, int &sum)
    {
        if(curr->last != 0)
            sum+= curr->last;
        for(int i = 0; i < 26; i++)
        {
            if(curr->next[i])
                dfs(curr->next[i], sum);
        }
    }
    int sum(string s) {
        TrieNode *curr = root;
        int res = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(curr->next[s[i]-'a'] == NULL)
                return res;
            curr = curr->next[s[i] - 'a'];
        }
        dfs(curr, res);
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum obj = new MapSum();
 * obj.insert(key,val);
 * int param_2 = obj.sum(prefix);
 */