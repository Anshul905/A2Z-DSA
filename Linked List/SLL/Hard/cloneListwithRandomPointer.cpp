/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {

        // //using map ( 2*n , n(map)+n(question demands) ) = (n,n)
        // map< Node* , Node* > m ;
        // Node* temp = head;
        // while(temp){
        //     m[temp] = new Node(temp->val);
        //     temp = temp->next;
        // }
        // temp = head;
        // while(temp){
        //     Node* copyNode = m[temp];
        //     copyNode->next = m[temp->next];
        //     copyNode->random = m[temp->random];
        //     temp = temp->next;
        // }
        // return m[head];



        // ( 3*n,n(question demands) ) = (n,1)
        // 1. insert copy node in between 
        Node* temp = head;
        while(temp){
            Node* newNode = new Node(temp->val);
            newNode->next = temp->next;
            temp->next = newNode;
            temp = temp->next->next;
        }
        // 2. connect random pointer 
        temp = head;
        while(temp){
            if(temp->random)
                temp->next->random = temp->random->next; 
            else
                temp->next->random = nullptr;
            temp = temp->next->next;
        }
        // 3. connect next pointer 
        Node* dummy = new Node(-1);
        Node* cur = dummy;
        temp = head;
        while(temp){
            cur->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            cur = cur->next;
        }

        return dummy->next;


    }
};