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
    vector<int> preorder(Node* root) {
        vector<int> res;
        helper(root, res);
        return res;
    }
    void helper(Node* root, vector<int> &holder)
    {
        if(root == NULL)
            return;
        holder.push_back(root->val);
        for(auto child : root->children)
            helper(child, holder);
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
    vector<int> preorder(Node* root) {
        vector<int> res;
        if(root == NULL)
            return res;
        stack<Node*> s;
        s.push(root);
        while(s.size() != 0)
        {
            Node* curr = s.top();
            s.pop();
            for(int i = curr->children.size() - 1; i>=0; i--)
                s.push(curr->children[i]);
            res.push_back(curr->val);
        }
        return res;
    }
};