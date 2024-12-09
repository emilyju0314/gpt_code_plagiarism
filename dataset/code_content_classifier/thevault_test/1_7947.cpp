long sim_random(EVOLVE_RANDOM *er)
{
	register long i;
	register int f, r;

	f = er->fidx;
	r = er->ridx;

	er->state[f] += er->state[r];
	i = (er->state[f] >> 1) & 0x7fffffff;	/* chucking least random bit */

	if( ++f >= EVOLVE_DEG4 ) {
		f = 0;
		r += 1;
	} else if( ++r >= EVOLVE_DEG4 ) {
		r = 0;
	}

	er->fidx = f;
	er->ridx = r;

	return i;
}