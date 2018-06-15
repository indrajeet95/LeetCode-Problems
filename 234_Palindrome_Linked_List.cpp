/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    ListNode* reverse(ListNode* root)
    {
        ListNode* prev = NULL;
        ListNode* curr = root;
        while(curr)
        {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* middle(ListNode* root)
    {
        ListNode* p1 = root;
        ListNode* p2 = root;
        while(p2 && p2->next)
        {
            p2 = p2->next->next;
            p1 = p1->next;
        }
        return p1;
    }

    bool isPalindrome(ListNode* root) {
        if(root == NULL || root->next == NULL)
            return true;
        ListNode* curr = root;
        ListNode* mid = middle(curr);
        ListNode* new_curr = reverse(mid);
        while(curr!=NULL && new_curr!=NULL)
        {
            if(curr->val != new_curr->val)
                return false;
            curr = curr->next;
            new_curr = new_curr->next;
        }
        return true;
    }
};
