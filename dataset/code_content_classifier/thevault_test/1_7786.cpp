struct Rect RTreeNodeCover(struct Node *N) {
	register struct Node *n = N;
	register int i, first_time=1;
	struct Rect r;
	assert(n);

	RTreeInitRect(&r);
	for (i = 0; i < NODECARD; i++)
		if (n->branch[i].child) {
			if (first_time) {
				r = n->branch[i].rect;
				first_time = 0;
			} else
				r = RTreeCombineRect(&r, &(n->branch[i].rect));
		}
	return r;
}