inline void sfmt_init_gen_rand(sfmt_t * sfmt, uint32_t seed) {
		int i;

		uint32_t *psfmt32 = &sfmt->state[0].u[0];

		psfmt32[idxof(0)] = seed;
		for (i = 1; i < SFMT_N32; i++) {
			psfmt32[idxof(i)] = 1812433253UL * (psfmt32[idxof(i - 1)]
				^ (psfmt32[idxof(i - 1)] >> 30))
				+ i;
		}
		sfmt->idx = SFMT_N32;
		period_certification(sfmt);
	}