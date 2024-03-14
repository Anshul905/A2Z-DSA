bool hasCycle(ListNode *head) {
    
    // unordered_map<ListNode*,int> m;
    // ListNode* temp = head;
    // while(temp){
    //     if( m.find(temp)!=m.end() ){
    //         return true;
    //     }
    //     m[temp] = 1;
    //     temp = temp->next;
    // }
    // return false;


    ListNode *slow = head , *fast = head ;
    while( fast && fast->next ){
        slow = slow->next ;
        fast = fast->next->next ;
        if( slow==fast )
            return true;
    }
    return false; 

}


// Using map : n*(2*log(n)) or n*(2) ,n
// optimal : ~~n,1