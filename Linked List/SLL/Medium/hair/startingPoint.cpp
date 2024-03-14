    ListNode* detectCycle(ListNode* head) {

        // unordered_map<ListNode*,int> m;
        // ListNode* temp = head;
        // while(temp){
        //     if( m.find(temp)!=m.end() ){
        //         return temp;
        //     }
        //     m[temp] = 1;
        //     temp = temp->next;
        // }
        // return nullptr;

        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return nullptr;
    }


// Using map : n*(2*log(n)) or n*(2) ,n
    // first node which is already visited (in the map) 
// optimal : ~~n,1
    // once you found cycle, make one point to head and find the common find by increasing both by 1 



//                 a   C(L1)
//             a              a
// A  a B(L1)                    a
//             a               a
//                 a        a   
//                     D


// A to B : L1 ( slow at B) ( dis : L1)
// B to C : L1 ( fast at C) ( dis : L1+L1)

// C to B : d ( fast need d time to cover d distance )
// cycle = B to D = ( B to C ) + ( C to B ) = L1 + d 


// Meeting point ( D ) , somehow we need to prove A to B is wqual to D to B

//                 a   C(L1)
//             a              a
// A  a B(L1)                    a
//             a               a
//                 a        a   
//                     D(d)

// B to D : d ( slow will move d distance )
// so if B to D is d and cycle is (L1+d) then D to A must be L1 

// cycle = L1 + d = ( B to D ) + ( D to B ) = d = ( D to B)
// so D to B == L1 

// so now 
// A to B is L1 and D to B is L1 
// both are equal , hence we move once pointer to head and keep increasing one each time until both becomes equal , the only point it will become equal is starting point 





