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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == NULL)
            return NULL;
        if(headB == NULL)
            return NULL;
        ListNode* currA = headA;
        ListNode* currB = headB;
        while(currA != currB)
        {
            if(currA == NULL)
                currA = headB;
            else
                currA = currA->next;
            if(currB == NULL)
                currB = headA;
            else
                currB = currB->next;
        }
        return currA;
    }
};