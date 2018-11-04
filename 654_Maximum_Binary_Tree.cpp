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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructors(nums,0, nums.size());
    }
    TreeNode* constructors(vector<int> nums, int l, int r)
    {
        if(l == r)
            return NULL;
        int root_pointer = getIndex(nums,l,r);
        TreeNode* curr = new TreeNode(nums[root_pointer]);
        curr->left = constructors(nums, l, root_pointer);
        curr->right = constructors(nums, root_pointer + 1, r);
        return curr;
    }
    int getIndex(vector<int> input, int l, int r)
    {
        int res = l;
        int val = input[l];
        for(int i = l; i<r; i++)
        {
            if(val < input[i])
            {
                val = input[i];
                res = i;
            }
        }
        return res;
    }
};