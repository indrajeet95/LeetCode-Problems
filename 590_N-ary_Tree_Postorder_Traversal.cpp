/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        helper(root,res);
        return res;
    }
    void helper(Node* root, vector<int> &res)
    {
        if(root == NULL)
            return;
        for(auto child: root->children)
            helper(child, res);
        res.push_back(root->val);
    }
};

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        stack<Node*> s;
        s.push(root);
        while(s.size() != 0)
        {
            Node* curr = s.top();
            s.pop();
            for(auto child : curr->children)
                s.push(child);
            res.push_back(curr->val);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};