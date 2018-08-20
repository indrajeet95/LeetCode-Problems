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
    ListNode* insertionSortList(ListNode* head) {
        if(head == NULL)
            return NULL;
        vector<int> sortinput;
        ListNode* curr = head;
        while(curr!=NULL)
        {
            sortinput.push_back(curr->val);
            curr = curr->next;
        }
        sort(sortinput.begin(),sortinput.end());
        ListNode* ans = new ListNode(sortinput[0]);
        ListNode* ans1 = ans;
        for(int i=1;i<sortinput.size();i++)
        {
            ans->next = new ListNode(sortinput[i]);
            ans = ans->next;
        }
        return ans1;
    }
};