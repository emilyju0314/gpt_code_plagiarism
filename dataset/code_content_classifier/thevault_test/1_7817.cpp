void RTreeRandomRect(struct Rect *R)
{
	register struct Rect *r = R;
	register int i;
	register RectReal width;
	for (i = 0; i < NUMDIMS; i++)
	{
		/* width from 1 to 1000 / 4, more small ones
		*/
		width = drand48() * (1000 / 4) + 1;

		/* sprinkle a given size evenly but so they stay in [0,100]
		*/
		r->boundary[i] = drand48() * (1000-width); /* low side */
		r->boundary[i + NUMDIMS] = r->boundary[i] + width; // high side
	}
}