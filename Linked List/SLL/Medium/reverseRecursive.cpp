ListNode* reverseList(ListNode* head) {

    if(!head || !head->next)
        return head;

    ListNode* front = head->next ;
    ListNode* newhead = reverseList(front);
    front->next = head;//main step
    head->next = nullptr; //imp step

    return newhead;

}

// brute : use stack , (n,n) 
// optimised : n,1