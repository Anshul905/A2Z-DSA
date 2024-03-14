int getLength(ListNode* head){
    int cnt = 0;
    ListNode* temp = head ;
    while(temp){
        temp = temp->next ;
        cnt++;
    }
    return cnt;
}
ListNode* removeNthFromEnd(ListNode* head, int n) {
    
    // if(!head)
    //     return nullptr ;

    // int len = getLength(head);
    
    // if(n==len){
    //     head = head->next;
    //     return head;
    // }
    // ListNode* prev = nullptr;
    // ListNode* cur = head;

    // while( cur ){
    //     if( len==n ){
    //         prev->next = cur->next;
    //         return head;
    //     }
    //     prev = cur;
    //     cur = cur->next;
    //     len--;
    // }
    // return head;

    ListNode*  fast = head ;
    for(int i=0;i<n;i++)
        fast = fast->next;
    
    if(!fast){
        head = head->next;
        return head;
    }

    ListNode*  slow = head ;
    while(fast->next){
        slow = slow->next;
        fast = fast->next;
    }    
    // ListNode*  delNode = slow->next ;
    slow->next = slow->next->next ;
    // delete delNode;
    return head;
}


// Brute : len+(len-n) , 1 
// optimal : len,1 ( using slow and fast , move fast n step ahead then both together )
