Node* reverse(Node* head){
    if(!head || !head->next)
        return head;
    
    Node* front = head->next ;
    Node* reversedHead = reverse(front);
    front->next = head; //main step
    head->next = nullptr; //imp step 
    return reversedHead;
}

int fun(Node* &head){
    if(!head)
        return 1;
    
    int temp = fun(head->next);

    // optimization 
    // if(temp==0)
    //     return 0;

    int sum = head->data + temp ;
    if(sum==10){
        head->data = 0;
        return 1;
    }else{
        head->data = sum;
        return 0;
    }

}

Node *addOne(Node *head)
{
    // reverse , do , reverse
    // head = reverse( head );
    // Node* cur = head;

    // int carry = 1;
    // while(cur){
    //     int sum = cur->data + carry ;
    //     if(sum==10){
    //         cur->data = 0;
    //         carry = 1;
    //     }else{
    //         cur->data = sum ;
    //         carry = 0;
    //         break;
    //     }
    //     cur = cur->next ;
    // }
    // head = reverse( head );
    // if(carry==1){
    //     Node* newHead = new Node(1);
    //     newHead->next = head;
    //     head = newHead; 
    // }

    // return head;


    int carry = fun(head);
    if(carry==1){
        Node* newHead = new Node(1);
        newHead->next = head;
        head = newHead; 
    }

    return head;

}

// Brute : 3n,1
    // reverse , do , reverse

// optimal : n,1 
    // ( using recursion if we dont want to reverse ) ( in one pass )
