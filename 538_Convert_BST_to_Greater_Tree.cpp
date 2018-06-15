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
    int sum = 0;
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)
            return NULL;
        if(root->right)
            convertBST(root->right);
        sum += root->val;
        root->val = sum;
        if(root->left)
            convertBST(root->left);
        return root;
    }
};
