/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

TO UNDERSTAND

Let us the say the linekd list that we have is 
2 -> 3 -> 5 -> NULL
and the addresses are as follows: 1221 -> 1222 -> 1223 -> NULL

the unordered map will look like 
1221 : 2221
1222 : 2222
1223 : 2223
where 2221, 2222 and 2223 are all new linked list nodes. 

Now we need to provide connections for next and random pointer in our copied linked list. 
Iterate over the orginal linked list and assign the pointer values to corresponding ones. 

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        unordered_map<RandomListNode*, RandomListNode*> mp;
        RandomListNode* m = head;
        RandomListNode* n = head;
        while(m != NULL)
        {
            mp[m] = new RandomListNode(m->label);
            m = m->next;
        }
        while(n != NULL)
        {
            mp[n]->next = mp[n->next];
            mp[n]->random = mp[n->random];
            n = n->next;
        }
        return mp[head];
    }
};