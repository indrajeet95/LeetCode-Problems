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
    bool isValidBST(TreeNode* root) {
        return isValid(root,LONG_MIN,LONG_MAX);
    }
    bool isValid(TreeNode* root,long min, long max)
    {
        if(root == NULL)
            return true;
        if(root->val<=min || root->val>=max)
            return false;
        return isValid(root->left,min,root->val) && isValid(root->right,root->val,max);
    }
};
