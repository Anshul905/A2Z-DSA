Node *deleteNode(Node *head, int k)
{
	if( !head )
		return nullptr;
	
	if(k==0){
		head = head->next;
		return head;
	}
	Node* prev = nullptr;
	Node* cur = head;
	int cnt=0;

	while( cur ){
		if( cnt==k ){
			prev->next = cur->next;
			free(cur);
			return head;
		}
		prev = cur;
		cur = cur->next;
		cnt++;
	}
	return head;
}
