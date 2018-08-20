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
    void reorderList(ListNode* head) {
        ListNode* curro = head;
        ListNode* dummy = new ListNode(0);
        ListNode* dummys = dummy;
        dummy->next = curro;
        while(curro!=NULL)
        {
            ListNode* curr = new ListNode(curro->val);
            dummy->next = curr;
            dummy = dummy->next;
            curro = curro->next;
        }
        ListNode* rhead = reverse(dummys->next);
        ListNode* curr = head;
        ListNode* rcurr = rhead;
        while(curr!=NULL && rcurr!=NULL && curr->val != rcurr->val)
        {
            ListNode* forward = curr->next;
            ListNode* rforward = rcurr->next;
            curr->next = rcurr;
            rcurr->next = forward;
            curr = forward;
            rcurr = rforward;
        }
        ListNode* middlea = middle(head);
        if(middlea->next != NULL)
            middlea->next = NULL;
    }
    ListNode* middle(ListNode* head)
    {
        ListNode* mid = new ListNode(0);
        ListNode* p = head;
        if(mid->next == NULL)
            mid->next = p;
        ListNode* pp = head;
        while(pp!=NULL && pp->next != NULL)
        {
            p = p->next;
            pp = pp->next->next;
            mid = mid->next;
        }
        return mid;
    }
    ListNode* reverse(ListNode* head)
    {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr)
        {
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
};

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
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)
            return;
        
        ListNode* p = head;
        ListNode* pp = head;
        while(pp->next != NULL && pp->next->next != NULL)
        {
            p = p->next;
            pp = pp->next->next;
        }
        
        ListNode* prev = p;
        cout << prev->val;
        ListNode* curr = prev->next;
        while(curr->next!=NULL)
        {
            ListNode* forward = curr->next;
            curr->next = forward->next;
            forward->next = prev->next;
            prev->next = forward;
        }
        
        p = head;
        pp = prev->next;
        while(p != prev)
        {
            prev->next = pp->next;
            pp->next = p->next;
            p->next = pp;
            p = pp->next;
            pp = prev->next;
        }

    }
};