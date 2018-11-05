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
    int maxPathSum(TreeNode* root) {
        //int res = INT_MIN;
        int res = INT_MIN;
        helper(root, res);
        return res;
    }
    int helper(TreeNode* root, int &res)
    {
        if(root == NULL)
            return 0;
        int l = helper(root->left, res);
        int r = helper(root->right, res);
        if(l<0)
            l = 0;
        if(r<0)
            r = 0;
        if(root->val + l + r > res)
            res = root->val + l + r;
        return root->val + max(l, r);
    }
};