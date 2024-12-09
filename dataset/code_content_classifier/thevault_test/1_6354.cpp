struct node* TreeInsert(struct node* node, int key, struct TrieNode* address) 
{ 
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key,address); 

	/* Otherwise, recur down the tree */
	if (key < node->key) 
		node->left = TreeInsert(node->left, key, address); 
	else if(key > node->key)
		node->right = TreeInsert(node->right, key, address); 

	/* return the (unchanged) node pointer */
	return node; 
}