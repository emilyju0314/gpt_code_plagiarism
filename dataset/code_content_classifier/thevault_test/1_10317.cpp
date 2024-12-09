inline void sfmt_gen_rand_all(sfmt_t * sfmt) {
		int i;
		__m128i r1, r2;
		w128_t * pstate = sfmt->state;

		r1 = pstate[SFMT_N - 2].si;
		r2 = pstate[SFMT_N - 1].si;
		for (i = 0; i < SFMT_N - SFMT_POS1; i++) {
			mm_recursion(&pstate[i].si, pstate[i].si,
				pstate[i + SFMT_POS1].si, r1, r2);
			r1 = r2;
			r2 = pstate[i].si;
		}
		for (; i < SFMT_N; i++) {
			mm_recursion(&pstate[i].si, pstate[i].si,
				pstate[i + SFMT_POS1 - SFMT_N].si,
				r1, r2);
			r1 = r2;
			r2 = pstate[i].si;
		}
	}