inline static uint32_t sfmt_genrand_uint32(sfmt_t * sfmt) {
		uint32_t r;
		uint32_t * psfmt32 = &sfmt->state[0].u[0];

		if (sfmt->idx >= SFMT_N32) {
			sfmt_gen_rand_all(sfmt);
			sfmt->idx = 0;
		}
		r = psfmt32[sfmt->idx++];
		return r;
	}