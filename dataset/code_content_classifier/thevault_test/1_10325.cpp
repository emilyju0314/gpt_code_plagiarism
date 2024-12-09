inline void sfmt_fill_array32(sfmt_t * sfmt, uint32_t *array, int size) {
		assert(sfmt->idx == SFMT_N32);
		assert(size % 4 == 0);
		assert(size >= SFMT_N32);

		gen_rand_array(sfmt, (w128_t *)array, size / 4);
		sfmt->idx = SFMT_N32;
	}