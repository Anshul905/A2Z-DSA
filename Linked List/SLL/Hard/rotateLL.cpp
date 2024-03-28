/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode* head){
        ListNode* temp = head;
        int len = 0;
        while(temp){
            len++;
            temp = temp->next;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {

        // ( n+n-k , 1 )
        if(!head || !head->next || k==0 )
            return head;

        // int len = getLength(head);
        ListNode* last = head;
        int len = 1;
        while(last->next){
            len++;
            last = last->next;
        }
        k = k%len;
        if(k==0)
            return head;

        int i=0;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(i<(len-k)){
            pre = cur;
            cur = cur->next;
            i++;
        }
        pre->next = nullptr ;
        last->next = head;
        return cur;

    }
};