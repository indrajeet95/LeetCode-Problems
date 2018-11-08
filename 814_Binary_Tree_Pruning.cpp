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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if(root->left == NULL && root->right == NULL && root->val == 0)
            return NULL;
        return root;
    }
};

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
    TreeNode* pruneTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        if(helper(root))
            return root;
        else
            return NULL;
    }
    
    bool helper(TreeNode* root)
    {
        if(root == NULL)
            return false;
        bool a = helper(root->left);
        bool b = helper(root->right);
        if(a == false)
            root->left = NULL;
        if(b == false)
            root->right = NULL;
        return a | b | root->val == 1; //everything here is OR because the question is fine when atleast one node in the left or right subtree contains a 1. If everything is zero then you make it NULL.
        
    }
};