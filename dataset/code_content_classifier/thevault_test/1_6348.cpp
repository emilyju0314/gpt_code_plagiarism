Node* LLInsert(Node* node, int key, struct TrieNode* address) { 
	/* If the list is empty, return a new node */
	if (node == NULL) return newNode(key,address); 

	/* Otherwise, go through the list */
	Node* run = node;
    while(run->next != NULL) {
        run = run->next;
    }

    run->next = newNode(key, address);

	/* Return the (unchanged) node pointer */
	return node; 
}