/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        return traverse(s,t);
    }
    bool same(TreeNode* s,TreeNode* t)
    {
        if(s==NULL && t==NULL)
            return true;
        if(s==NULL || t==NULL)
            return false;
        return s->val == t->val && same(s->left,t->left) && same(s->right,t->right);
    }
    bool traverse(TreeNode* s, TreeNode* t)
    {
        if(s==NULL)
            return false;
        return same(s,t) || traverse(s->left,t) || traverse(s->right,t);
    }
};
