struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isRoot;
};

class Solution {
private:
    TrieNode* root = new TrieNode();
    //root->isRoot = false;
public:
    
    void insert(string word) {
        TrieNode* curr = root;
        for(auto ch : word) {
            if(curr->children.find(ch) == curr->children.end())
                curr->children[ch] = new TrieNode();
            curr = curr->children[ch];
        }
        curr->isRoot = true;
    }
    
    string searchShortestPrefix(string word) {
        string prefix = "";
        bool prefixFound = false;
        TrieNode* curr = root;
        auto ch = word.begin();
        while(curr->children[*ch] != NULL && !prefixFound) {
            prefix += *ch;
            if(curr->children[*ch]->isRoot)
                prefixFound = true;
            curr = curr->children[*ch];
            ++ch;
        }
        if(prefixFound)
            return prefix;
        else
            return word;
    }
    
    string replaceWords(vector<string>& dict, string sentence) {
        //store the words in sentence in a vector
        vector<string> words;
        string holder;
        string res = "";
        stringstream iss(sentence); 
        // Read and print each word. 
        while (iss >> holder)
            words.push_back(holder);
        //insert all the roots into a Trie
        for(int i=0; i<words.size(); i++)
            cout << words[i] << " ";
        for(auto word : dict) {
            insert(word);
        }
        for(auto word : words) {
            string holder = searchShortestPrefix(word);
            res += holder + " ";
        }
        res.pop_back();
        return res;
    }
};