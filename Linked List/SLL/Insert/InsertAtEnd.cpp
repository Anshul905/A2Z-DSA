Node* insertEnd(Node* head, int k) {

    if(!head){
        Node* temp = new Node(k);
        head = temp;
        return head;
    }

    Node* cur = head;
    while(cur->next){
        cur = cur->next;
    }
    Node* temp = new Node(k);
    cur->next = temp ;
    // free(temp);
    return head;
}