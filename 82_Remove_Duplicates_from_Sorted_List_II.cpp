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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* curr = dummy;
        int dup = 0;
        while(curr->next!=NULL && curr->next->next!=NULL)
        {
            if(curr->next->val == curr->next->next->val)
            {
                dup = curr->next->val;
                while(curr->next!=NULL && curr->next->val == dup)
                {
                    curr->next = curr->next->next;
                }
            }
            else
                curr = curr->next;
        }
        return dummy->next;
    }
};
