ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    
    if(!list1)
        return list2;
    if(!list2)
        return list1;
    
    ListNode* curA = list1 ;
    ListNode* curB = list2 ;
    ListNode* dummy = new ListNode(200) ;
    ListNode* ans = dummy; 

    while(curA && curB){
        if( curA->val < curB->val ){
            ans->next = curA ;
            curA = curA->next;
        }else{
            ans->next = curB ;
            curB = curB->next;
        }
        ans = ans->next;
    }
    ans->next = ( curA ? curA : curB );
    
    return dummy->next;
}

// 2 pointer approach : min(n1,n2)+other  = n1+n2