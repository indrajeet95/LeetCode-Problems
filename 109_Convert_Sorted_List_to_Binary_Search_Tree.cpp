/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* cur = head;
        ListNode* prev = new ListNode(0);
        prev->next = head;
        int len = length(head);
        for(int i=0;i<(len/2);i++)
        {
            cur = cur->next;
            prev = prev->next;
        }
        TreeNode* root = new TreeNode(10);
        if(cur != NULL)
            root->val = cur->val;
        prev->next = cur->next;
        ListNode* temp = head;
        while(temp!=NULL)
        {
            insert(root,temp->val);
            temp = temp->next;
        }
        return root;
        
    }
    int length(ListNode* head)
    {
        int l = 1;
        if(head == NULL)
            return 0;
        while(head->next != NULL)
        {
            l++;
            head = head->next;
        }
        return l;
    }
    struct TreeNode* insert(struct TreeNode* node, int key)
    {
        if(node == NULL)
            return new TreeNode(key);
    if (key < node->val)
        node->left  = insert(node->left, key);
    else if (key > node->val)
        node->right = insert(node->right, key);
    return node;
    }
};