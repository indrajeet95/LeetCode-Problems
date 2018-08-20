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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* prev = new ListNode(0);
        prev->next = head;
        ListNode* ans = prev;
        int nm = n - m;
        while(m>1)
        {
            prev = prev->next;
            m--;
        }
        ListNode* curr = prev->next;
        while(nm>0)
        {
            ListNode* forward = curr->next;
            curr->next = curr->next->next;
            forward->next = prev->next;
            prev->next = forward;
            nm--;
        }
        return ans->next;
    }
};
