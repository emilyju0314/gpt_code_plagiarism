inline void sfmt_fill_array64(sfmt_t * sfmt, uint64_t *array, int size) {
		assert(sfmt->idx == SFMT_N32);
		assert(size % 2 == 0);
		assert(size >= SFMT_N64);

		gen_rand_array(sfmt, (w128_t *)array, size / 2);
		sfmt->idx = SFMT_N32;

#if defined(BIG_ENDIAN64) && !defined(ONLY64)
		swap((w128_t *)array, size / 2);
#endif
	}