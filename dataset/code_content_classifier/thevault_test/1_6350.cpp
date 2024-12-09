bool TrieSearch(struct TrieNode *root, string key) { 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) { 
		int index = key[i] - 'a'; 
        cout << "KEY: " << index << "\n";
		if(!LLSearch((Node *)pCrawl->root,index)) {
			return false; 
        }
        		
		pCrawl = LLSearch((Node *)pCrawl->root,index)->address; 
	} 

    return (pCrawl != NULL && pCrawl->isEndOfWord);
}