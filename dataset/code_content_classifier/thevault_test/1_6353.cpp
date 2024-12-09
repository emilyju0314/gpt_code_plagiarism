struct node *newNode(int item, struct TrieNode *address) 
{ 
	struct node *temp = (struct node *)malloc(sizeof(struct node)); 
	memory += sizeof(struct node) + 8;
	temp->key = item; 
	temp->address = address;
	temp->left = temp->right = NULL; 
	return temp; 
}