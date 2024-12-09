void TrieInsert(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if(!TreeSearch((node *)pCrawl->root,index))
			pCrawl->root = TreeInsert((node *)pCrawl->root,index,getNode(index));
		
		pCrawl->descendents+=1;
		pCrawl = TreeSearch((node *)pCrawl->root,index)->address;

	} 

	// mark last node as leaf 
	pCrawl->isEndOfWord = true; 
}