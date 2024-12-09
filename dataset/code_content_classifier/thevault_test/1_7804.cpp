void RTreeInitRect(struct Rect *R)
{
	register struct Rect *r = R;
	register int i;
	for (i=0; i<NUMDIMS; i++)
		r->boundary[i] = (RectReal)0;
	
	//memset(r->trie, ' ', TRIELEN);
	//memset(r->minstr, ' ', MAXLEN);
	//memset(r->maxstr, ' ', MAXLEN);
	//r->trie = new char[TRIELEN];
	r->trie = new string();

	r->realtrie = new Trie();

	r->compratio = 1;

	//r->nfa = NULL;
}