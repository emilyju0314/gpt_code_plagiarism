inline static void period_certification(sfmt_t * sfmt) {
		uint32_t inner = 0;
		int i, j;
		uint32_t work;
		uint32_t *psfmt32 = &sfmt->state[0].u[0];
		const uint32_t parity[4] = { SFMT_PARITY1, SFMT_PARITY2,
			SFMT_PARITY3, SFMT_PARITY4 };

		for (i = 0; i < 4; i++) {
			inner ^= psfmt32[idxof(i)] & parity[i];
		}
		for (i = 16; i > 0; i >>= 1) {
			inner ^= inner >> i;
		}
		inner &= 1;
		/* check OK */
		if (inner == 1) {
			return;
		}
		/* check NG, and modification */
		for (i = 0; i < 4; i++) {
			work = 1;
			for (j = 0; j < 32; j++) {
				if ((work & parity[i]) != 0) {
					psfmt32[idxof(i)] ^= work;
					return;
				}
				work = work << 1;
			}
		}
	}