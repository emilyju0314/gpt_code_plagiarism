static void RTreeLoadNodes(struct Node *n, struct Node *q,
			struct PartitionVars *p)
{
	register int i;
	assert(n);
	assert(q);
	assert(p);

	for (i=0; i<NODECARD+1; i++)
	{
		assert(p->partition[i] == 0 || p->partition[i] == 1);
		if (p->partition[i] == 0)
			RTreeAddBranch(&BranchBuf[i], n, NULL);
		else if (p->partition[i] == 1)
			RTreeAddBranch(&BranchBuf[i], q, NULL);
	}
}