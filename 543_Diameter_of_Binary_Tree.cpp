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
    int maxs = 0;
    int depth(struct TreeNode* root)
    {
        if(root == NULL)
            return 0;
        int left = depth(root->left);
        int right = depth(root->right);
        maxs = max(maxs,left+right);
        return 1 + max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return maxs;
    }
};
