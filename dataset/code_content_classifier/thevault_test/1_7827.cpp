int RTreeContained(struct Rect *R, struct Rect *S)
{
	register struct Rect *r = R, *s = S;
	register int i, j, result;
	assert(static_cast<int>(reinterpret_cast<uintptr_t>(r)) &&
               static_cast<int>(reinterpret_cast<uintptr_t>(s)));

 	// uintptr_t rect is contained in any other
	//
	if (Undefined(r))
		return TRUE;

	// no rect (except an uintptr_t one) is contained in an undef rect
	//
	if (Undefined(s))
		return FALSE;

	result = TRUE;
	for (i = 0; i < NUMDIMS; i++)
	{
		j = i + NUMDIMS;  /* index for high sides */
		result = result
			&& r->boundary[i] >= s->boundary[i]
			&& r->boundary[j] <= s->boundary[j];
	}
	return result;
}