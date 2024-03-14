Node* constructLL(vector<int>& arr) {    
    Node* head = new Node(arr[0]);
    Node* moving = head ;

    for(int i=1;i<arr.size();i++){
        Node* temp = new Node(arr[i]);
        moving->next = temp ;
        moving = temp;
    }
    return head;
}