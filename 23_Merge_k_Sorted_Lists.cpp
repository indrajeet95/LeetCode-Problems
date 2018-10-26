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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 0)
            return NULL;
        else
        {
            while(lists.size()>1)
            {
                ListNode* a = lists[0];
                ListNode* b = lists[1];
                lists.push_back(mergeTwoLists(a,b));
                lists.erase(lists.begin());
                lists.erase(lists.begin());            
            }
        }
        return lists.front();
        
    }
    
    ListNode* mergeTwoLists(ListNode* a, ListNode* b)
    {
        if(a == NULL)
            return b;
        else if(b == NULL)
            return a;
        if(a->val <= b->val)
        {
            a->next = mergeTwoLists(a->next, b);
            return a;
        }
        else
        {
            b->next = mergeTwoLists(a, b->next);
            return b;
        }
    }
};
---------------------------------------------------
Divide and Conquer


ListNode* mergeKLists(vector<ListNode*>& lists) {
    int k = (int)lists.size();
    if(k==0) return NULL;
    if(k==1) return lists[0];
    return doMerge(lists, 0, (int)lists.size()-1);
}


ListNode* doMerge(vector<ListNode*>& lists, int left, int right) {
    if(left==right) return lists[left];
    else if(left+1==right) return merge2Lists(lists[left], lists[right]);
    ListNode* l1 = doMerge(lists, left, (left+right)/2);
    ListNode* l2 = doMerge(lists, (left+right)/2+1, right);
    return merge2Lists(l1, l2);
}


ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
    if(l1==l2) return l1;
    if(!l1) return l2;
    if(!l2) return l1;
    if(l1->val>l2->val) return merge2Lists(l2, l1);
    ListNode* newl2 = new ListNode(0); newl2->next = l2;
    ListNode* p1 = l1;
    while (p1->next && newl2->next) {
        if (p1->next->val<newl2->next->val) {
            p1 = p1->next;
        } else {
            ListNode* temp = p1->next;
            p1->next = newl2->next;
            newl2->next = newl2->next->next;
            p1->next->next = temp;
            p1 = p1->next;
        }
    }
    if(!p1->next) p1->next = newl2->next;
    delete newl2;
    return l1;
}
---------------------------------------------------
Min Heap

class Solution {
    struct compare {
      bool operator() (ListNode* l1, ListNode* l2) {
          return l1->val > l2->val;
      }  
    };
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        priority_queue<ListNode *, vector<ListNode *>, compare> q;
        for (auto l : lists) {
            if (l) {
                q.push(l);
            }
        }
        
        if (q.empty()) {
            return NULL;
        }
//        while(q.size())
//        {
  ///          cout << q.top()->val << endl;
     //       q.pop();
       // }
//            cout << q->val << endl;
        
        ListNode* result = q.top();
        q.pop();
        if (result->next) {
            q.push(result->next);
        }

        ListNode* tail = result;            
        while (!q.empty()) {
            tail->next = q.top();
            q.pop();
            tail = tail->next;
            if (tail->next) {
                q.push(tail->next);
            }
        }
        
        return result;
    }
};