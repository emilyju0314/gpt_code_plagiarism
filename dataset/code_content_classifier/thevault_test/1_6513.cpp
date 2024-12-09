int
CBQueue::eligible_formal(CBQClass *cl, double now)
{
	int level;
	CBQClass *p;

	// check from leaf level to (cl->level - 1)
	for (level = LEAF_LEVEL; level < cl->level_; level++) {
		p = levels_[level];
		while (p != NULL) {
			if (!p->satisfied(now))
				return (0);
			p = p->level_peer_;
		}
	}
	return (1);
}