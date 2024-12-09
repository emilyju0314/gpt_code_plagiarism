static void RTreeGetBranches(struct Node *N, struct Branch *B)
{
	register struct Node *n = N;
	register struct Branch *b = B;
	register int i;

	assert(n);
	assert(b);

	/* load the branch buffer */
	for (i=0; i<NODECARD; i++)
	{
		assert(n->branch[i].child);  /* every entry should be full */
		BranchBuf[i] = n->branch[i];
	}
	BranchBuf[NODECARD] = *b;
	BranchCount = NODECARD + 1;

	/* calculate rect containing all in the set */
	CoverSplit = BranchBuf[0].rect;
	for (i=1; i<NODECARD+1; i++)
	{
		CoverSplit = RTreeCombineRect(&CoverSplit, &BranchBuf[i].rect);
	}

	RTreeInitNode(n);
}