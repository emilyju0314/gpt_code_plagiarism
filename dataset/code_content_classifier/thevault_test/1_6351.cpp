bool isEmpty(TrieNode* root) 
{ 
	Node *ptr = (Node *)root->root;
	if (ptr != NULL && ptr->next == NULL)
		return false;
	return true;
}