/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy=new ListNode(0);
        ListNode* res=dummy;
        int n=lists.size();
        priority_queue<ListNode*,vector<ListNode*>,compare> pq;
        for(int i=0;i<n;i++)
        {
            if(lists[i]) pq.push(lists[i]);
        }
        while(!pq.empty())
        {
            ListNode* curr=pq.top();
            pq.pop();
            res->next=curr;
            res=curr;
            if(curr->next!=NULL)
            {
                pq.push(curr->next);
            }
        }
        return dummy->next;
    }
};