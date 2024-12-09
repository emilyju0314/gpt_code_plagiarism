static int read_er(PHASCII_INSTANCE pi, UNIVERSE *u, char *errmsg)
{
	int n, i, num, fidx, ridx;
	long state;
	EVOLVE_RANDOM *er;

	ASSERT( pi != NULL );
	ASSERT( errmsg != NULL );

	if( u == NULL ) {
		sprintf(errmsg, "a UNIVERSE instance must appear before ER instance");
		return 0;
	}

	if( u->er != NULL ) {
		sprintf(errmsg, "multiple ER instances not allowed");
		return 0;
	}

	n = Phascii_Get(pi, "ER.FIDX", "%d", &fidx);
	if( n != 1 ) {
		sprintf(errmsg, "missing ER.FIDX");
		return 0;
	}

	n = Phascii_Get(pi, "ER.RIDX", "%d", &ridx);
	if( n != 1 ) {
		sprintf(errmsg, "missing ER.RIDX");
		return 0;
	}

	n = Phascii_Get(pi, "ER.STATE.N", "%d", &num);
	if( n != 1 ) {
		sprintf(errmsg, "missing ER.STATE.N");
		return 0;
	}

	if( num != EVOLVE_DEG4 ) {
		sprintf(errmsg, "ER.STATE.N = %d should be %d", num, EVOLVE_DEG4);
		return 0;
	}

	er = sim_random_make(123);

	er->fidx = fidx;
	er->ridx = ridx;

	for(i=0; i < n; i++) {
		n = Phascii_Get(pi, "ER.STATE[%0].VALUE", i, "%ld", &state);

		if( n != 1 ) {
			sprintf(errmsg, "ER.STATE[%d].VALUE missing", i);
			return 0;
		}

		er->state[i] = state;
	}

	u->er = er;

	return 1;
}