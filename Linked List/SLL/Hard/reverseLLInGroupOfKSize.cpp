class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next)
            return head;
        ListNode* front = head->next;
        ListNode* rev = reverseList(front);
        front->next = head;
        head->next = nullptr;
        return rev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        // Recursive : ( 2*n,stack ) = (n,stack)
        ListNode* temp = head;
        int cnt = 0;
        while (temp) {
            cnt++;
            if (cnt == k)
                break;
            temp = temp->next;
        }
        if (cnt != k)
            return head;

        ListNode* next = temp->next;
        temp->next = nullptr;

        // head to temp
        ListNode* rev = reverseList(head);
        // next to last
        ListNode* remain = reverseKGroup(next, k);
        head->next = remain;
        return rev;





        // Iterative ( 2*n , 1 ) = ( n , 1 )
        // ListNode* dummy = new ListNode(-1);
        // ListNode* before = dummy;
        // ListNode* after = head;

        // while(true){

        //     ListNode* temp = after;
        //     int i=0;
        //     while(i<k){
        //         if(temp==nullptr)
        //             return dummy->next;
        //         temp = temp->next;
        //         i++;
        //     }

        //     ListNode* cur = after;
        //     ListNode* pre = before;

        //     int j=0;
        //     while(j<k){
        //         ListNode* front = cur->next;
        //         cur->next = pre;
        //         pre = cur;
        //         cur = front;
        //         j++;
        //     }
        //     before->next = pre;
        //     after->next = cur;
        //     before = after ;
        //     after = cur ;
        // }
    }
};

// recursive : (2n,stack) = (n,1)
// Iterative : (2n,1)     = (n,1)
