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
    void helper(vector<string> &res, TreeNode* root,string data)
    {
        if(root->left == NULL && root->right == NULL)
        {
            res.push_back(data);
            return;
        }
        if(root->left)
            helper(res,root->left,data+"->"+to_string(root->left->val));
        if(root->right)
            helper(res,root->right,data+"->"+to_string(root->right->val));
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == NULL)
            return res;
        helper(res,root,to_string(root->val));
        return res;
    }
};
