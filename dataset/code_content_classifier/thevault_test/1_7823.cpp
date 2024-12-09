RectReal RTreeRectSurfaceArea(struct Rect *R)
{
	register struct Rect *r = R;
	register int i, j;
	register RectReal sum = (RectReal)0;

	assert(r);
	if (Undefined(r))
		return (RectReal)0;

	for (i=0; i<NUMDIMS; i++) {
		RectReal face_area = (RectReal)1;
		for (j=0; j<NUMDIMS; j++)
			/* exclude i extent from product in this dimension */
			if(i != j) {
				RectReal j_extent =
					r->boundary[j+NUMDIMS] - r->boundary[j];
				face_area *= j_extent;
			}
		sum += face_area;
	}
	return 2 * sum;
}