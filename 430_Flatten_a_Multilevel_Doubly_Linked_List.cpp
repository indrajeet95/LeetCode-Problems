/*
// Definition for a Node.
class Node {
public:
    int val = NULL;
    Node* prev = NULL;
    Node* next = NULL;
    Node* child = NULL;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if(head == NULL)
            return NULL;
        Node* p = head;
        while(p != NULL)
        {
            if(p->child == NULL)
            {
                p = p->next;
                continue;
            }
            Node* temp = p->child;
            while(temp->next != NULL)
                temp = temp->next;
            temp->next = p->next;
            if(temp->next != NULL)
                temp->next->prev = temp;
            p->next = p->child;
            p->child->prev = p;
            p->child = NULL;
        }
        return head;
    }
};