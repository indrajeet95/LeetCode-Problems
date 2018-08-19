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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;
        ListNode* curr = head;
        ListNode* prev = new ListNode(NULL);
        prev->next = head;
        ListNode* tmp = prev;
        while(curr!=NULL && curr->next != NULL)
        {
            prev->next = curr->next;
            prev = prev->next;
            curr->next = prev->next;
            prev->next = curr;
            prev = curr;
            curr = curr->next;
        }
        return tmp->next;
    }
};
