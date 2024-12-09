void md5_transform (const void* x)
{
	uint32_t s[4];
	uint8_t  i, n, r;

	for (i = 0; i < 4; i++)
		s[i] = state[i];

	for (r = 0; r < 4; r++) /* round */
	{
		for (n = 0; n < 16; n++)
		{
			i = md5_rotr (27, n % 4 * 2); /* 27 = 00 01 10 11 (0 1 2 3) */
			TRAN (r, s[(i >> 6) & 3], s[(i >> 4) & 3], s[(i >> 2) & 3], s[i & 3], *((uint32_t*)x + (md5_X[r][0] + n * md5_X[r][1]) % 16), md5_T[r][n], md5_S[r][n % 4]);
		}
	}

	for (i = 0; i < 4; i++)
		state[i] += s[i];
}