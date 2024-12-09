inline static void gen_rand_array(sfmt_t * sfmt, w128_t * array, int size)
	{
		int i, j;
		uint32x4_t r1, r2;
		w128_t * pstate = sfmt->state;

		r1 = pstate[SFMT_N - 2].si;
		r2 = pstate[SFMT_N - 1].si;
		for (i = 0; i < SFMT_N - SFMT_POS1; i++) {
			neon_recursion(&array[i].si, pstate[i].si, pstate[i + SFMT_POS1].si, r1, r2);
			r1 = r2;
			r2 = array[i].si;
		}
		for (; i < SFMT_N; i++) {
			neon_recursion(&array[i].si, pstate[i].si, array[i + SFMT_POS1 - SFMT_N].si, r1, r2);
			r1 = r2;
			r2 = array[i].si;
		}
		for (; i < size - SFMT_N; i++) {
			neon_recursion(&array[i].si, array[i - SFMT_N].si, array[i + SFMT_POS1 - SFMT_N].si, r1, r2);
			r1 = r2;
			r2 = array[i].si;
		}
		for (j = 0; j < 2 * SFMT_N - size; j++) {
			pstate[j] = array[j + size - SFMT_N];
		}
		for (; i < size; i++, j++) {
			neon_recursion(&array[i].si, array[i - SFMT_N].si, array[i + SFMT_POS1 - SFMT_N].si, r1, r2);
			r1 = r2;
			r2 = pstate[j].si = array[i].si;
		}
	}