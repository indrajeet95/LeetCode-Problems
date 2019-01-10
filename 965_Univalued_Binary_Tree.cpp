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
    bool isUnivalTree(TreeNode* root) {
        if(root == NULL)
            return false;
        if(root->left == NULL && root->right == NULL)
            return true;
        int comp = root->val;
        bool res = true;
        inorder(root, comp, res);
        return res;
    }
    void inorder(TreeNode* curr, int comp, bool &res)
    {
        if(curr == NULL)
            return;
        inorder(curr->left, comp, res);
        if(curr->val != comp)
            res = false;
        inorder(curr->right, comp, res);
    }
};