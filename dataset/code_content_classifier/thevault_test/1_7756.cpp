static void RTreeGetBranches(struct Node *n, struct Branch *b)
{
	register int i;

	assert(n);
	assert(b);

	/* load the branch buffer */
	for (i=0; i<NODECARD; i++)
	{
		assert(n->branch[i].child); /* n should have every entry full */
		BranchBuf[i] = n->branch[i];
	}
	BranchBuf[NODECARD] = *b;

	/* calculate rect containing all in the set */
	CoverSplit = BranchBuf[0].rect;
	for (i=1; i<NODECARD+1; i++)
	{
		CoverSplit = RTreeCombineRect(&CoverSplit, &BranchBuf[i].rect);
	}
	CoverSplitArea = RTreeRectSphericalVolume(&CoverSplit);

	RTreeInitNode(n);
}