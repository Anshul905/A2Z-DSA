Node* sortList(Node *head){

    if(!head || !head->next)
        return head;

    Node* zeroHead = new Node(-10) ;
    Node* oneHead = new Node(-10) ;
    Node* twoHead = new Node(-10) ;
    Node *zeroMoving = zeroHead , *oneMoving = oneHead , *twoMoving = twoHead;
    Node* cur = head ;

    while(cur){
        if(cur->data==0){
            zeroMoving->next = cur ;
            zeroMoving = zeroMoving->next;
        }else if(cur->data==1){
            oneMoving->next = cur ;
            oneMoving = oneMoving->next;
        }else{
            twoMoving->next = cur ;
            twoMoving = twoMoving->next;
        }
        cur = cur->next;
    }
    twoMoving->next = nullptr;
    oneMoving->next = twoHead->next ;
    zeroMoving->next = oneHead->next ;

    return zeroHead->next;
 
}


// Brute : nlogn,1

// Better : 2n,1
    // first pass to count 0,1,2
    // second to replace nodes data 

//optimal : n,1
    // make 3 dummy node , attach them carefully 