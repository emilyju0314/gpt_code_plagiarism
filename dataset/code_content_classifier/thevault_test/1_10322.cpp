inline static void gen_rand_array(sfmt_t * sfmt, w128_t *array, int size) {
		int i, j;
		w128_t *r1, *r2;

		r1 = &sfmt->state[SFMT_N - 2];
		r2 = &sfmt->state[SFMT_N - 1];
		for (i = 0; i < SFMT_N - SFMT_POS1; i++) {
			do_recursion(&array[i], &sfmt->state[i], &sfmt->state[i + SFMT_POS1], r1, r2);
			r1 = r2;
			r2 = &array[i];
		}
		for (; i < SFMT_N; i++) {
			do_recursion(&array[i], &sfmt->state[i],
				&array[i + SFMT_POS1 - SFMT_N], r1, r2);
			r1 = r2;
			r2 = &array[i];
		}
		for (; i < size - SFMT_N; i++) {
			do_recursion(&array[i], &array[i - SFMT_N],
				&array[i + SFMT_POS1 - SFMT_N], r1, r2);
			r1 = r2;
			r2 = &array[i];
		}
		for (j = 0; j < 2 * SFMT_N - size; j++) {
			sfmt->state[j] = array[j + size - SFMT_N];
		}
		for (; i < size; i++, j++) {
			do_recursion(&array[i], &array[i - SFMT_N],
				&array[i + SFMT_POS1 - SFMT_N], r1, r2);
			r1 = r2;
			r2 = &array[i];
			sfmt->state[j] = array[i];
		}
		}