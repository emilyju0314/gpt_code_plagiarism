static void RTreeInitPVars(struct PartitionVars *p)
{
	register int i;
	assert(p);

	p->count[0] = p->count[1] = 0;
	p->cover[0] = p->cover[1] = RTreeNullRect();
	p->area[0] = p->area[1] = (RectReal)0;
	for (i=0; i<NODECARD+1; i++)
	{
		p->taken[i] = FALSE;
		p->partition[i] = -1;
	}
}