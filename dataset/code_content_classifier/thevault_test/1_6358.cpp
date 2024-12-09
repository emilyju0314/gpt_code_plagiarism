bool TrieSearch(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if(!TreeSearch((node *)pCrawl->root,index))
			return false; 
		
		pCrawl = TreeSearch((node *)pCrawl->root,index)->address; 
	} 

	return (pCrawl != NULL && pCrawl->isEndOfWord); 
}