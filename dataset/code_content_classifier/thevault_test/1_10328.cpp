inline void sfmt_init_by_array(sfmt_t * sfmt, uint32_t *init_key, int key_length) {
		int i, j, count;
		uint32_t r;
		int lag;
		int mid;
		int size = SFMT_N * 4;
		uint32_t *psfmt32 = &sfmt->state[0].u[0];

		if (size >= 623) {
			lag = 11;
		}
		else if (size >= 68) {
			lag = 7;
		}
		else if (size >= 39) {
			lag = 5;
		}
		else {
			lag = 3;
		}
		mid = (size - lag) / 2;

		memset(sfmt, 0x8b, sizeof(sfmt_t));
		if (key_length + 1 > SFMT_N32) {
			count = key_length + 1;
		}
		else {
			count = SFMT_N32;
		}
		r = func1(psfmt32[idxof(0)] ^ psfmt32[idxof(mid)]
			^ psfmt32[idxof(SFMT_N32 - 1)]);
		psfmt32[idxof(mid)] += r;
		r += key_length;
		psfmt32[idxof(mid + lag)] += r;
		psfmt32[idxof(0)] = r;

		count--;
		for (i = 1, j = 0; (j < count) && (j < key_length); j++) {
			r = func1(psfmt32[idxof(i)] ^ psfmt32[idxof((i + mid) % SFMT_N32)]
				^ psfmt32[idxof((i + SFMT_N32 - 1) % SFMT_N32)]);
			psfmt32[idxof((i + mid) % SFMT_N32)] += r;
			r += init_key[j] + i;
			psfmt32[idxof((i + mid + lag) % SFMT_N32)] += r;
			psfmt32[idxof(i)] = r;
			i = (i + 1) % SFMT_N32;
		}
		for (; j < count; j++) {
			r = func1(psfmt32[idxof(i)] ^ psfmt32[idxof((i + mid) % SFMT_N32)]
				^ psfmt32[idxof((i + SFMT_N32 - 1) % SFMT_N32)]);
			psfmt32[idxof((i + mid) % SFMT_N32)] += r;
			r += i;
			psfmt32[idxof((i + mid + lag) % SFMT_N32)] += r;
			psfmt32[idxof(i)] = r;
			i = (i + 1) % SFMT_N32;
		}
		for (j = 0; j < SFMT_N32; j++) {
			r = func2(psfmt32[idxof(i)] + psfmt32[idxof((i + mid) % SFMT_N32)]
				+ psfmt32[idxof((i + SFMT_N32 - 1) % SFMT_N32)]);
			psfmt32[idxof((i + mid) % SFMT_N32)] ^= r;
			r -= i;
			psfmt32[idxof((i + mid + lag) % SFMT_N32)] ^= r;
			psfmt32[idxof(i)] = r;
			i = (i + 1) % SFMT_N32;
		}

		sfmt->idx = SFMT_N32;
		period_certification(sfmt);
	}