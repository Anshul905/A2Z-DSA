ListNode* deleteMiddle(ListNode* head) {

    if(!head->next)
        return nullptr;

    ListNode *slow = head , *fast = head ;
    ListNode* prev = nullptr;
    while( fast && fast->next ){
        prev = slow ;
        slow = slow->next ;
        fast = fast->next->next ;
    }
    prev->next = slow->next;
    delete slow ;
    return head;
}

// keep prev one node back to slow 
// and whenever you get middle, delete slow by making slow->next as prev->next  
// ( you get middle node just before you go out of the loop so write condition outside ) 