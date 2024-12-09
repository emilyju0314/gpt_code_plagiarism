TrieNode *TrieRemove(TrieNode *root, string key, int depth = 0)
{
	// If tree is empty
	if (!root)
		return NULL;

	// If last character of key is being processed
	if (depth == key.size())
	{

		// This node is no more end of word after
		// removal of given key
		if (root->isEndOfWord)
			root->isEndOfWord = false;

		// If given is not prefix of any other word
		if (isEmpty(root))
		{
			delete (root);
			root = NULL;
		}

		return root;
	}

	// If not last character, recur for the child
	// obtained using ASCII value
	int index = key[depth] - 'a';
	Node *ptr = SearchAVL((Node *)root->root, index);
	InsertAVL((Node *)root->root, index, TrieRemove(ptr->address, key, depth + 1));

	// If root does not have any child (its only child got
	// deleted), and it is not end of another word.
	if (isEmpty(root) && root->isEndOfWord == false)
	{
		delete (root);
		root = NULL;
	}
	else
		root->descendants -= 1;

	return root;
}