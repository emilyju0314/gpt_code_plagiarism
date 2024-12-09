struct Rect RTreeNullRect()
{
	struct Rect r;
	//register int i;

	r.boundary[0] = (RectReal)1;
	r.boundary[NUMDIMS-1] = (RectReal)-1;
	
	/*for (i=1; i<NUMDIMS; i++)
		r.boundary[i] = r.boundary[i+NUMDIMS] = (RectReal)0;*/
	/*comment by liang*/
	//memset(r.trie, ' ', TRIELEN);
	//memset(r.minstr, ' ', MAXLEN);
	//memset(r.maxstr, ' ', MAXLEN);
	//r.trie = new char[MAXLEN];
	//r.trie = new string();
	
	return r;
}