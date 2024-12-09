bool TrieSearch(struct TrieNode *root, string key)
{
	struct TrieNode *pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i] - 'a';
		if (!SearchAVL((Node *)pCrawl->root, index))
			return false;

		Node *temp = SearchAVL((Node *)pCrawl->root, index);
		pCrawl = temp->address;
	}

	return (pCrawl != NULL && pCrawl->isEndOfWord);
}