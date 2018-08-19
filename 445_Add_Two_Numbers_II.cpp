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
        stack<int> s1;
        stack<int> s2;
        while(l1 != NULL)
        {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2 != NULL)
        {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int sum = 0;
        ListNode* front = new ListNode(0);
        while(s1.size()!=0 || s2.size()!=0)
        {
            if(s1.size() != 0)
            {
                sum += s1.top();
                s1.pop();                
            }
            if(s2.size() != 0)
            {
                sum += s2.top();
                s2.pop();            
            }
            front->val = sum%10;
            ListNode* head = new ListNode(sum/10);
            head->next = front;
            front = head;
            sum = sum/10;
        }
        if(front->val == 0)
            return front->next;
        else
            return front;
    }
};
