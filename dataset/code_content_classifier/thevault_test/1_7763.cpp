extern void RTreeSplitNode(struct Node *n, struct Branch *b, struct Node **nn)
{
	register struct PartitionVars *p;
	register int level;

	assert(n);
	assert(b);

	/* load all the branches into a buffer, initialize old node */
	level = n->level;
	RTreeGetBranches(n, b);

	/* find partition */
	p = &Partitions[0];
	RTreeMethodZero(p);

	/*
	 * put branches from buffer into 2 nodes
	 * according to chosen partition
	 */
	*nn = RTreeNewNode();
	(*nn)->level = n->level = level;
	RTreeLoadNodes(n, *nn, p);
	assert(n->count+(*nn)->count == NODECARD+1);
}