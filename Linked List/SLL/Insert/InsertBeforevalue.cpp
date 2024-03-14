Node* insertBeforeValue(Node* head, int x, int val){
    if(head->data==val){
        Node* temp = new Node(x);
        temp->next = head;
        head = temp;
        return head;
    }
    Node* prev = nullptr;
    Node* cur = head;

    while(cur){
        if(cur->data==val){
            Node* temp = new Node(x);
            prev->next = temp;
            temp->next = cur ;
            return head;
        }
        prev = cur;
        cur = cur->next;
    }
    Node* temp = new Node(x);
    prev->next = temp;
    return head;
}
