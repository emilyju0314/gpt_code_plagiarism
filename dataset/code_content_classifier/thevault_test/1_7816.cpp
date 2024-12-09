struct Rect RTreeNullRect()
{
	struct Rect r;
	register int i;

	r.boundary[0] = (RectReal)1;
	r.boundary[NUMDIMS] = (RectReal)-1;
	for (i=1; i<NUMDIMS; i++)
		r.boundary[i] = r.boundary[i+NUMDIMS] = (RectReal)0;
	return r;
}