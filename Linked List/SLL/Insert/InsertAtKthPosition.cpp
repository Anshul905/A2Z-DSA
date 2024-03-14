Node * insert(Node * head, int n, int pos, int val) {
    if(pos==0){
        Node* temp = new Node(val);
        temp->next = head;
        head = temp;
        return head;
    }
    Node* prev = nullptr;
    Node* cur = head;
    int cnt=0;

    while(cur){
        if(cnt==pos){
            Node* temp = new Node(val);
            prev->next = temp;
            temp->next = cur ;
            return head;
        }
        cnt++;
        prev = cur;
        cur = cur->next;
    }
    Node* temp = new Node(val);
    prev->next = temp;
    return head;
}