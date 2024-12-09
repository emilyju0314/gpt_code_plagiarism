void TrieInsert(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		pCrawl->descendants += 1;
		Node *temp = SearchAVL((Node *)pCrawl->root, index);
		if (!temp)
			pCrawl->root = InsertAVL((Node *)pCrawl->root, index, getNode(index));

		temp = SearchAVL((Node *)pCrawl->root, index);
		pCrawl = temp->address;
	}

	// mark last node as leaf
	pCrawl->isEndOfWord = true;
}