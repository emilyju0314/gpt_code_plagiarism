bool isEmpty(TrieNode* root) 
{ 
	node *ptr = (node *)root->root;
	if (ptr != NULL)
		return false;
	return true;
}