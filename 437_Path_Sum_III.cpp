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
    int pathSum(TreeNode* root, int sum) {
        if(root == NULL)
            return 0;
        int count = helper(root,sum) + pathSum(root->left,sum) + pathSum(root->right,sum);
        return count;
    }
    int helper(TreeNode* root, int sum)
    {
        if(root == NULL)
            return 0;
        //cout << "Value =" << (sum == root->val);
        return (sum==root->val) + helper(root->left,sum - root->val) + helper(root->right,sum - root->val);
    }
};