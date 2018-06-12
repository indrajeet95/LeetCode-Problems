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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* curr1 = dummy;
        ListNode* curr2 = dummy;
        ListNode* prev2 = dummy;
        if(head == NULL)
            return head;
        if(head->next == NULL)
            return NULL;
        while(n)
        {
            curr1 = curr1->next;
            n--;
        }
        while(curr1)
        {
            prev2 = curr2;
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        prev2->next = curr2->next;
        return dummy->next;
    }
};