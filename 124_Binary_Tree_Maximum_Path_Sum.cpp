IDEA:
Basically you start at some bottom place and keep moving up and then start going down. You cannot go up again. 
So recrusively, finish the left hand side and then move to the right. Pass res by reference and keep updating through the whole process
The helper method tells you 

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
WRONG
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
        int res = INT_MIN;
        res = max(res, maxPath(root));
        return res;
    }
    int maxPath(TreeNode* curr)
    {
        if(curr == NULL)
            return 0;
        else if(curr->left == NULL && curr->right == NULL)
            return curr->val;
        else
            return curr->val + maxPath(curr->left) + maxPath(curr->right);
    }
};