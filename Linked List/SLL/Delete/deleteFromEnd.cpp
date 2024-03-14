Node *deleteLast(Node *head){

    if(!head || !head->next)
        return nullptr;

    Node* cur = head ;
    while( cur->next->next )
        cur = cur->next ;
    delete cur->next ;
    cur->next = nullptr;
    return head;
}