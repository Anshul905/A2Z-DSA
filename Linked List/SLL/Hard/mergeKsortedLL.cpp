class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // use vector to store all value , sort , put in dummy list
        // ( n + nlogn , n ) where  n is the no of all node
        // vector<int> values ;
        // for(int i=0;i<lists.size();i++){
        //     ListNode* head = lists[i];
        //     while(head){
        //         values.push_back(head->val);
        //         head = head->next;
        //     }
        // }
        // sort(values.begin(),values.end());

        // ListNode* dummy = new ListNode(-1) ;
        // ListNode* add = dummy ;
        // for(auto it:values){
        // 	add->next = new ListNode(it);
        // 	add = add->next;
        // }
        // return dummy->next;




        // merge first two list and then merge it with third ans so on ....
        //  (m*(k*(k+1))/2 , 1 ) , when k==m ( m*m*m , 1 ) , m is the average
        //  length of list ( n*k , 1 ) where n = m*k ( n is the total nodes )
        //  if(lists.size()==0)
        //      return nullptr;
        //  ListNode* l1 = lists[0];
        //  for(int i=1;i<lists.size();i++){
        //      ListNode* l2 = lists[i];
        //      l1 = merge2sortedLL(l1,l2);
        //  }
        //  return l1;




        // use priority queue , compare all k lists at once
        //  ( klog(k)+ (n-k)log(k) , n+k )
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>,
                       greater<pair<int, ListNode*>>>
            pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i])
                pq.push({lists[i]->val, lists[i]});
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* add = dummy;
        while (!pq.empty()) {
            auto it = pq.top();
            pq.pop();
            add->next = it.second;
            add = add->next;

            ListNode* front = (it.second)->next;
            if (front)
                pq.push({front->val, front});
        }
        return dummy->next;
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
};