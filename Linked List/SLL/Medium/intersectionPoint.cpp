    void shift(ListNode* &cur , int diff){
    while(diff){                
        diff--;
        cur = cur->next;
    }
}
int findLength(ListNode* temp){
    int c=0;
    while(temp){
        c++;
        temp = temp->next ;
    }
    return c;
}
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // // brute
    // map<ListNode*,bool> m ;
    // ListNode* temp = headA ;
    // while(temp){
    //     m[temp] = true ;
    //     temp = temp->next ;
    // }
    // temp = headB ;
    // while(temp){
    //     if(m.find(temp)!=m.end()){
    //         return temp;                
    //     }
    //     temp = temp->next ;
    // }
    // return nullptr; 





    // // better
    // // finding length ( l1+l2 )        
    // int l1 = findLength(headA); 
    // int l2 = findLength(headB); 

    // // shifting (diff = ~~n )
    // ListNode* curA = headA ;
    // ListNode* curB = headB ;
    // int diff = abs(l1-l2);
    // if(l1>l2)
    //     shift(curA,diff);
    // else
    //     shift(curB,diff);

    // // finding intersection ( min(l1,l2) ~~ n)
    // while(curA != curB){
    //     curA = curA->next;
    //     curB = curB->next;
    // }
    // return curA;




    // optimal
    ListNode* curA = headA ;
    ListNode* curB = headB ;
    while(curA != curB){
        // curA ? cout<<curA->val<<" " : cout<<"null " ;
        // curB ? cout<<curB->val<<endl : cout<<"null"<<endl ;

        curA = ( curA ? curA->next : headB );
        curB = ( curB ? curB->next : headA );
    }
    return curA;

}

// Brute : (l1*map time)*(l2*map time) , l1 

// Better : l1+l2 + diff + min(l1,l2) = l1+l2+max(l1,l2) , 1  

// optimal : max(l1,l2)[ till both points to same level ]+min(l1,l2) = l1+l2 , 1
