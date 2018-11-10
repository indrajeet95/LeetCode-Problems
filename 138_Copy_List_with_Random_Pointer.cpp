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


/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        RandomListNode* p = head;
        //RandomListNode* p = head;
        RandomListNode* q;
        if(head == NULL)
            return NULL;
        while(p != NULL)
        {
            q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
        p = head;
        while(p != NULL)
        {
            q = p->next;
            if(p->random != NULL)
                q->random = p->random->next;
            p = q->next;
        }
        RandomListNode* old = head;
        RandomListNode* newnewhead = head->next;
        while(old != NULL)
        {
            q = old->next;
            old->next = q->next;
            old = old->next;
            if(old)
                q->next = old->next;
        }
        return newnewhead;
        
    }
};
/*
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode * head) {
        RandomListNode * head_cp = nullptr, * cur = head, * cur_cp = nullptr;
        if (head == nullptr)
            return nullptr;
        while (cur != nullptr)
        {
            cur_cp = new RandomListNode (cur->label);
            cur_cp->next = cur->next;
            cur->next = cur_cp;
            cur = cur_cp->next;
        }
        cur = head;
        while (cur != nullptr)
        {
            cur_cp = cur->next;
            if (cur->random)
                cur_cp->random = cur->random->next;
            cur = cur_cp ->next;
        }
        cur = head;
        head_cp = head->next;
        while (cur != nullptr)
        {
            cur_cp = cur->next;
            cur->next = cur_cp->next;
            cur = cur->next;
            if (cur)
                cur_cp->next = cur->next;
        }
        return head_cp;
    }
};

/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == NULL)
            return NULL;
        RandomListNode* p = head;
        while(p != NULL)
        {
            RandomListNode* q = new RandomListNode(p->label);
            q->next = p->next;
            p->next = q;
            p = q->next;
        }
        p = head;
        while(p != NULL)
        {
            RandomListNode* q = p->next;
            if(p->random != NULL)
                q->random = p->random->next;
            p = q->next;
        }
        RandomListNode* old = head;
        RandomListNode* newhead = head->next;
        RandomListNode* newnewhead = newhead;
        while(old != NULL)
        {
            old->next = newhead->next;
            if(newhead->next != NULL)
                newhead->next = newhead->next->next;
            old = old->next;
            newhead = newhead->next;
        }
        return newnewhead;
        
    }
};