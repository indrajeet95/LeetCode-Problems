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
    vector<int> res;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL)
            return res;
        inorder(root);
        return res;
    }
};
