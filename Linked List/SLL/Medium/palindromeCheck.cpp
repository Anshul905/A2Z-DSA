ListNode* reverse(ListNode* head){
    if(!head || !head->next)
        return head;
    
    ListNode* front = head->next ;
    ListNode* reversedHead = reverse(front);
    front->next = head; //main step
    head->next = nullptr; //imp step 
    return reversedHead;
}
bool isPalindrome(ListNode* head) {

    if(!head || !head->next)
        return head;
    // find centre and reverse right half and compare 

    ListNode *slow = head , *fast = head ;

    // finding middle
    while( fast->next && fast->next->next ){
        slow = slow->next ;
        fast = fast->next->next;
    }

    // reversing right half
    ListNode* newHead = reverse( slow->next );
    slow->next = reverse( slow->next );//make the ll as it was , good practice 

    ListNode* temp = newHead ;
    ListNode* cur = head ;
    while(temp){
        if(cur->val!=temp->val)
            return false;
        cur = cur->next ;
        temp = temp->next ;
    }
    return true;
}


// Brute : n,n ( stack )
// Optimal : n,1 ( n/2 + n/2 + n/2 , 1 ) 
// find the middle ( hare and tortoise algorithm ) then reverse the second half ( slow->next) and check if values and return accordingly 

