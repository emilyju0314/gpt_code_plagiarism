void RTreePrintRect(struct Rect *R, int depth)
{
	register struct Rect *r = R;
	register int i;
	assert(r);

	RTreeTabIn(depth);
	printf("rect:\n");
	for (i = 0; i < NUMDIMS; i++) {
		RTreeTabIn(depth+1);
		printf("%f\t%f\n", r->boundary[i], r->boundary[i + NUMDIMS]);
	}
}