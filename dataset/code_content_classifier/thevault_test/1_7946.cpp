EVOLVE_RANDOM *sim_random_make(unsigned long seed)
{
	EVOLVE_RANDOM *er;
	register long i;

	er = (EVOLVE_RANDOM*) CALLOC(1, sizeof(EVOLVE_RANDOM));
	ASSERT( er != NULL );

	er->state[0] = seed;
	for(i = 1; i < EVOLVE_DEG4; i++) {
		er->state[i] = good_rand( er->state[i-1] );
	}

	er->fidx = EVOLVE_SEP4;
	er->ridx = 0;

	for(i = 0; i < 10 * EVOLVE_DEG4; i++) {
		(void)sim_random(er);
	}

	return er;
}