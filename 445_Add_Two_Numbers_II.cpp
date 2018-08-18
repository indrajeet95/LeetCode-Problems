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
        ListNode* p1 = reverse(l1);
        ListNode* p2 = reverse(l2);
        ListNode* head = new ListNode(0);
        ListNode* yobro = head;
        int carry = 0;
        while(p1 || p2)
        {
            int sum = carry;
            if(p1)
            {
                sum += p1->val;
                p1 = p1->next;                
            }
            if(p2)
            {
                sum += p2->val;
                p2 = p2->next;
            }
            carry = sum/10;
            sum = sum%10;
            ListNode* temp = new ListNode(sum);
            if(head->next == NULL)
                head->next = temp;
            head = head->next;
        }
        if(carry)
        {
            ListNode* temp = new ListNode(carry);
            if(head->next == NULL)
                head->next = temp;
        }
        return reverse(yobro->next);
    }
    
    ListNode* reverse(ListNode* head)
    {
        ListNode* prev = NULL;
        ListNode* cur = head;
        while(cur)
        {
            ListNode* forward = cur->next;
            cur->next = prev;
            prev = cur;
            cur = forward;
        }
        return prev;
    }
};