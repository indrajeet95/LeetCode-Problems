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
    int numComponents(ListNode* head, vector<int>& G) {
        int parts = 0;
        unordered_set<int> g(G.begin(),G.end());
        while(head != NULL)
        {
            if(g.count(head->val)>0 && (head->next == NULL || g.count(head->next->val)==0))
                parts++;
            head = head->next;
        }
        return parts;
    }
};
