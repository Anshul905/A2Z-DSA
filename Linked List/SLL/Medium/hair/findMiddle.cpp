ListNode* middleNode(ListNode* head) {    
    ListNode *slow = head , *fast = head ;
    while( fast && fast->next ){
        slow = slow->next ;
        fast = fast->next->next ;
    }
    return slow;
}

// Brute : n+n/2,1
// Optimal : n/2,1