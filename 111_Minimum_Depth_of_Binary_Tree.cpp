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
    int minDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        if(root->left == NULL && root->right == NULL)
            return 1;
        int min_depth = INT_MAX;
        if(root->left != NULL)
            min_depth = min(min_depth, minDepth(root->left));
        if(root->right != NULL)
            min_depth = min(min_depth, minDepth(root->right));
        return 1 + min_depth;
    }
};