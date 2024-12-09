int RTreePickBranch(struct Rect *R, struct Node *N) {
	register struct Rect *r = R;
	register struct Node *n = N;
	register struct Rect *rr;
	register int i, first_time=1;
	RectReal increase, bestIncr=(RectReal)-1, area, bestArea;
	int best;
	struct Rect tmp_rect;
	assert(r && n);

	for (i=0; i<NODECARD; i++) {
		if (n->branch[i].child) {
			rr = &n->branch[i].rect;
			area = RTreeRectSphericalVolume(rr);
			tmp_rect = RTreeCombineRect(r, rr);
			increase = RTreeRectSphericalVolume(&tmp_rect) - area;
			if (increase < bestIncr || first_time) {
				best = i;
				bestArea = area;
				bestIncr = increase;
				first_time = 0;
			} else if (increase == bestIncr && area < bestArea) {
				best = i;
				bestArea = area;
				bestIncr = increase;
			}
		}
	}
	return best;
}