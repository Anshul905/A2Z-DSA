Node * deleteHead(Node *head) {
    if(!head)
        return nullptr;
    
    head = head->next;
    return head;

}
