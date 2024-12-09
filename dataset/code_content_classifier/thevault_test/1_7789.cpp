int RTreeAddBranch(struct Branch *B, struct Node *N, struct Node **New_node) {
	register struct Branch *b = B;
	register struct Node *n = N;
	register struct Node **new_node = New_node;
	register int i;

	assert(b);
	assert(n);

	if (n->count < NODECARD)  /* split won't be necessary */ {
		for (i = 0; i < NODECARD; i++)  /* find empty branch */ {
			if (n->branch[i].child == NULL) {
				n->branch[i] = *b;
				n->count++;
				break;
			}
		}
		assert(i<NODECARD);
		return 0;
	} else {
		assert(new_node);
		RTreeSplitNode(n, b, new_node);
		return 1;
	}
}