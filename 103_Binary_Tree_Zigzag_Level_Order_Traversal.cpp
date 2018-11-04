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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == NULL)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        int flag = 1;
        while(q.size() != 0)
        {
            vector<int> row;
            int count = q.size();
            while(count > 0)
            {
                TreeNode* curr = q.front();
                q.pop();
                row.push_back(curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                count--;
            }
            if(flag == 1)
            {
                res.push_back(row);
                flag = 0;                
            }
            else
            {
                reverse(row.begin(),row.end());
                res.push_back(row);
                flag = 1;
            }
            
        }
        return res;
    }
};