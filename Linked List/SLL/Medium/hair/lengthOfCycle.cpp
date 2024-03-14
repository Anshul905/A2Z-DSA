int lengthOfLoop(Node *head) {

        // unordered_map<Node*,int> m;
        // Node* temp = head;
        // int cnt = 1;
        // while(temp){
        //     if( m.find(temp)!=m.end() ){
        //         return cnt-m[temp];
        //     }
        //     m[temp] = cnt++;
        //     temp = temp->next;
        // }
        // return 0;

        Node *slow = head , *fast = head ;
        while( fast && fast->next ){
            slow = slow->next ;
            fast = fast->next->next ;
            if( slow==fast ){
                int cnt=1;
                fast = fast->next;
                while(fast!=slow){
                    cnt++;
                    fast = fast->next;
                }
                return cnt;
            }

        }
        return 0; 

}

// Using map : n*(2*log(n)) or n*(2) ,n
// optimal : ~~n,1
