inline void sfmt_gen_rand_all(sfmt_t * sfmt) {
		int i;
		w128_t *r1, *r2;

		r1 = &sfmt->state[SFMT_N - 2];
		r2 = &sfmt->state[SFMT_N - 1];
		for (i = 0; i < SFMT_N - SFMT_POS1; i++) {
			do_recursion(&sfmt->state[i], &sfmt->state[i],
				&sfmt->state[i + SFMT_POS1], r1, r2);
			r1 = r2;
			r2 = &sfmt->state[i];
		}
		for (; i < SFMT_N; i++) {
			do_recursion(&sfmt->state[i], &sfmt->state[i],
				&sfmt->state[i + SFMT_POS1 - SFMT_N], r1, r2);
			r1 = r2;
			r2 = &sfmt->state[i];
		}
	}