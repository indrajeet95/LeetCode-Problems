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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp = root;
        TreeNode* insert = new TreeNode(val);
        if(root == NULL)
            return insert;
        while(true)
        {
            if(val > temp->val)
            {
                if(temp->right != NULL)
                    temp = temp->right;
                else
                {
                    temp->right = insert;
                    break;                    
                }
            }
            else if(val < temp->val)
            {
                if(temp->left != NULL)
                    temp = temp->left;
                else
                {
                    temp->left = insert;
                    break;
                }
            }
        }
        return root;
    }
};