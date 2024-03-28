
class Solution {
public:
    ListNode* sortList(ListNode* head) {

        // store in vector , sort it , replace value in list ( n + nlog(n) + n ,
        // n )
        //  vector<int> values;
        //  ListNode* temp = head;
        //  while(temp){
        //      values.push_back(temp->val);
        //      temp = temp->next;
        //  }

        // sort(values.begin(),values.end());

        // temp = head;
        // int i=0;
        // while(temp){
        //     temp->val = values[i];
        //     temp = temp->next;
        //     i++;
        // }
        // return head;




        // using merge sort ( n*log2(n)*(n/2) , 1 ) = ( n*log2(n) , 1)
        if (!head || !head->next)
            return head;

        // O(n/2)
        ListNode* mid = findMiddle(head);
        ListNode* leftHead = head;a
        cout<<"mid : "<<mid->val<<endl;
        ListNode* rightHead = mid->next;
        mid->next = nullptr;

        // log2(n)
        ListNode* left = sortList(leftHead);
        ListNode* right = sortList(rightHead);

        // O(n)
        return merge2sortedLL(left, right);
    }
    ListNode* merge2sortedLL(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;

        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;
            }
        }
        if (l1)
            cur->next = l1;
        else
            cur->next = l2;

        return dummy->next;
    }

    ListNode* findMiddle(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};