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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ahead = NULL;
        if(l1 == NULL)
            return l2;
        else if(l2 == NULL)
            return l1;
        if(l1->val < l2->val)
        {
            ahead = l1;
            l1 = l1->next;
        }
        else
        {
            ahead = l2;
            l2 = l2->next;
        }
        ListNode* head = ahead;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                head->next = l1;
                l1 = l1->next;
                head = head->next;
            }
            else
            {
                head->next = l2;
                l2 = l2->next;
                head = head->next;
            }
        }
        if(l1)
            head->next = l1;
        else if(l2)
            head->next = l2;
        return ahead;
    }
};