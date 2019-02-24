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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* curr = head;
        int carry = 0;
        while(l1 || l2)
        {
            int val1 = l1?l1->val:0;
            int val2 = l2?l2->val:0;
            int temp = val1 + val2 + carry;
            carry = temp/10;
            int val = temp%10;
            ListNode* node = new ListNode(val);
            curr->next = node;
            curr = curr->next;
            l1 = l1?l1->next:NULL;
            l2 = l2?l2->next:NULL;
        }
        if(l1 == NULL && l2 == NULL && carry == 1)
        {
            //cout << "yo";
            curr->next = new ListNode(1);
        }
        return head->next;
    }
};