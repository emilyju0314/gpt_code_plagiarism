void RTreeInitRect(struct Rect *R)
{
	register struct Rect *r = R;
	register int i;
	for (i=0; i<NUMSIDES; i++)
		r->boundary[i] = (RectReal)0;
}