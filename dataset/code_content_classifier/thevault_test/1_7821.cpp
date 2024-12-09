RectReal RTreeRectSphericalVolume(struct Rect *R)
{
	register struct Rect *r = R;
	register int i;
	RectReal maxsize=(RectReal)0, c_size;

	assert(r);
	if (Undefined(r))
		return (RectReal)0;
	for (i=0; i<NUMDIMS; i++) {
		c_size = r->boundary[i+NUMDIMS] - r->boundary[i];
		if (c_size > maxsize)
			maxsize = c_size;
	}
	return (RectReal)(pow(maxsize/2, NUMDIMS) * UnitSphereVolume);
}