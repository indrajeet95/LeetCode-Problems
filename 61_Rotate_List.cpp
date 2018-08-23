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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
        int len = 0;
        ListNode* prev = new ListNode(0);
        prev->next = head;
        ListNode* curr = head;
        while(curr != NULL)
        {
            prev = prev->next;
            curr = curr->next;
            len++;
        }
        if(k == len)
            return head;
        prev->next = head;
        int loc = len - (k%len);
        curr = head;
        for(int i=1;i<loc;i++)
            curr = curr->next;
        ListNode* temp = curr->next;
        curr->next = NULL;
        head = temp;
        return head;
    }
};