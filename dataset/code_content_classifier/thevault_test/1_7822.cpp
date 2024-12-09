RectReal RTreeRectSphericalVolume(struct Rect *R)
{
	register struct Rect *r = R;
	register int i;
	register double sum_of_squares=0, radius;

	assert(r);
	if (Undefined(r))
		return (RectReal)0;
	for (i=0; i<NUMDIMS; i++) {
		double half_extent =
			(r->boundary[i+NUMDIMS] - r->boundary[i]) / 2;
		sum_of_squares += half_extent * half_extent;
	}
	radius = sqrt(sum_of_squares);
	return (RectReal)(pow(radius, NUMDIMS) * UnitSphereVolume);
}