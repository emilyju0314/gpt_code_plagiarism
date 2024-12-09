void TrieInsert(struct TrieNode *root, string key) { 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) { 
		int index = key[i] - 'a'; 
		if(!LLSearch((Node *)pCrawl->root,index))
			pCrawl->root = LLInsert((Node *)pCrawl->root,index,getNode(index));

		pCrawl = LLSearch((Node *)pCrawl->root,index)->address;
	} 

	// mark last node as leaf 
	pCrawl->isEndOfWord = true; 
}