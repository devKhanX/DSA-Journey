class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode* p = head;
        ListNode* q = nullptr;
        ListNode* r = nullptr;
        while (p != nullptr) 
        {
            r = q;
            q = p;
            p = p->next;
            q->next = r; 
        }       
        return q; 
    }
};
