void deleteHead(node* &head) {

	if (head == NULL)
	{
		return; // If list is empty.
	}

	node* temp = head;

	head = head->next;
	delete temp;
}