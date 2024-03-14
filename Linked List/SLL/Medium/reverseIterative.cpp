ListNode* reverseList(ListNode* head) {

    if(!head || !head->next)
        return head;

    ListNode* prev = nullptr ;
    ListNode* cur = head;
    while(cur){
        ListNode* front = cur->next;
        cur->next = prev ;
        prev = cur;
        cur = front;
    }
    return prev;

}


// brute : use stack , (n,n) 
// optimised : n,1