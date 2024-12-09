bool isEmpty(TrieNode *root)
{
	Node *ptr = (Node *)root->root;
	if (ptr != NULL)
		return false;
	return true;
}