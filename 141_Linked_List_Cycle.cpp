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
    bool hasCycle(ListNode *head) {
        if(head==NULL || head->next == NULL)
            return false;
        unordered_set<ListNode*> temp;
        ListNode* p = head;
        while(p->next!=NULL)
        {
            if(temp.find(p)!=temp.end())
                return true;
            else
                temp.insert(p);
            p = p->next;
        }
        return false;
    }
};
