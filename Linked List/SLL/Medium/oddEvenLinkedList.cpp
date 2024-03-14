ListNode* oddEvenList(ListNode* head) {
    if(!head || !head->next || !head->next->next)
        return head;

    ListNode* oddMoving = head ;
    ListNode* even = head->next ;
    ListNode* evenMoving = even ;

    ListNode* cur = head->next->next ;

    bool inOdd = true;
    while(cur){
        if(inOdd){
            oddMoving->next = cur;
            oddMoving = oddMoving->next;
            evenMoving->next = nullptr ;
        }else{
            evenMoving->next = cur;
            evenMoving = evenMoving->next;
            oddMoving->next = nullptr ;
        }
        inOdd = !inOdd ;
        cur = cur->next;
    }  

    oddMoving->next = even ;
    return head;
}

// brute : n,n
// optimal : n,1
