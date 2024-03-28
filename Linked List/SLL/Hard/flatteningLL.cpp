#include <bits/stdc++.h>

Node* merge2sortedLL(Node* l1 , Node* l2){
	if( !l1 ) return l2;
	if (!l2 )  return l1;

	Node* dummy = new Node(-1);
	Node* cur = dummy;

	while( l1 && l2 ){
		if( l1->data < l2->data  ){
			cur->child = l1;
			cur = l1;
			l1 = l1->child;
		}else{
			cur->child = l2;
			cur = l2;
			l2 = l2->child;
		}
		cur->next = nullptr;
	}
	if(l1) cur->child = l1;
	else cur->child = l2;

	return dummy->child;
}

Node* flattenLinkedList(Node* head) 
{
		//(n + n*log(n),2*n ) = ( n + n*log(n) , n) where n is total no. of node ( 2n = vector + dummy here because we are creating n node to attach with it )
		// vector<int> values;
		// Node* temp = head ;
		// while(temp){
		// 	Node* cur = temp ;
		// 	while(cur){
		// 		values.push_back(cur->data);
		// 		cur = cur->child;
		// 	}
		// 	temp = temp->next;
		// }
		// sort(values.begin(),values.end());

		// Node* dummy = new Node(-1) ;
		// Node* add = dummy ;
		// for(auto it:values){
		// 	cout<<it<<" ";
		// 	add->child = new Node(it);
		// 	add->next = nullptr ;
		// 	add = add->child;
		// }

		// return dummy->next;





		// recursion ( n* 2*k , stack )
		// n -> recursion , 2*k merge function 
		if(!head)
			return head;

		Node* front = head->next;
		Node* ret = flattenLinkedList(front);
		Node* merged  = merge2sortedLL( head,ret );
		
		return merged;
}





		// Node* dummy = new Node(-1) ;
		// Node* add = dummy ;

		// Node* temp = head ;
		// Node* ret ;

		// while(temp){
		// 	// cout<<temp->data<<endl;
		// 	Node* front = temp->next;
		// 	Node* cur = temp ;
		// 	// cout<<"child : ";
		// 	while(cur){
		// 		// cout<<cur->data<<" ";	
		// 		add->next=cur;
		// 		add = add->next;
		// 		add->next = nullptr;

		// 		cur = cur->child;
		// 	}
		// 	temp = front;
		// 	// if(temp)
		// 		// cout<<"\t"<<temp->data<<endl;
			
		// 	// cout<<"Dummy : ";
		// 	// Node* d = dummy->next;
		// 	// while(d){	
		// 	// 	cout<<d->data<<" ";
		// 	// 	d = d->next;
		// 	// }
		// 	// cout<<endl;
		// 	// ret = dummy->next;
			
		// }

		// return ret;




