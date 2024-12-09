void insertAtMiddle(node* &head, int val, int idx) {
	node* n = new node(val);
	node*temp = head;
	idx--;
	while (idx != 1) {
		temp = temp->next;
		idx--;
	}
	// Here, order is very imp.
	n->next = temp->next;// First, update the next ptr of new node to the next node.
	temp->next = n;// Now we update the temp next ptr with the ptr of new node
}