ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* head  = new ListNode(11);
    ListNode* cur = head;

    int carry = 0 ;
    while(l1 || l2){
        
        int sum = carry;
        if(l1) sum += l1->val;
        if(l2) sum += l2->val;
        
        if(sum>9){
            sum = sum-10;
            carry = 1;
        }else{
            carry = 0 ;
        }
        ListNode* temp = new ListNode(sum);
        cur->next = temp;
        cur = cur->next;
        if(l1) l1 = l1->next ;
        if(l2) l2 = l2->next ;
    }

    if(carry){
        ListNode* temp = new ListNode(carry);
        cur->next = temp;
        cur = cur->next;
    }

    return head->next;
}

// max(n1,n2) , max(n1,n2) 