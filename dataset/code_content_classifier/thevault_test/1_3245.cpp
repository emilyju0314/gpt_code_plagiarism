const unsigned char * Search4(const unsigned char * buf, size_t buflen, const unsigned char * to_find, size_t max_back, size_t max_forw, int &ret_offset, int min_match /*=10*/)
{
	static const size_t chunk_size = sizeof(__m128i);
	assert((int)buf % chunk_size == 0); // ensure correct memory alignment
	assert(min_match >= 7);             // this is a requirement due to the way the search is performed

	// Set up the search patterns
	if (max_forw < 7)
		return NULL;                    // we need 7 bytes to fill our 4 patterns
	__m128i pat[4];
	pat[0].m128i_u32[0] = pat[0].m128i_u32[1] = pat[0].m128i_u32[2] = pat[0].m128i_u32[3] = *(unsigned __int32 *)(to_find+0);
	pat[1].m128i_u32[0] = pat[1].m128i_u32[1] = pat[1].m128i_u32[2] = pat[1].m128i_u32[3] = *(unsigned __int32 *)(to_find+1);
	pat[2].m128i_u32[0] = pat[2].m128i_u32[1] = pat[2].m128i_u32[2] = pat[2].m128i_u32[3] = *(unsigned __int32 *)(to_find+2);
	pat[3].m128i_u32[0] = pat[3].m128i_u32[1] = pat[3].m128i_u32[2] = pat[3].m128i_u32[3] = *(unsigned __int32 *)(to_find+3);

	__m128i * pp, *endbuf, cmp;
	ret_offset = -99;
	int which_dword = 0;                // bottom 4 bits are a mask which says which copy (or copies) of the pattern were matched
	const unsigned char * retval = NULL;

	//timer t(true);
	endbuf = (__m128i *)(buf + (buflen - buflen%chunk_size));
	assert((int)endbuf % chunk_size == 0);
	for (pp = (__m128i *)buf; pp < endbuf; ++pp)
	{
		for (int pnum = 0; pnum < 4; ++pnum)
		{
			cmp = _mm_cmpeq_epi32(pat[pnum], *pp);                           // PCMPEQD
			if (which_dword = _mm_movemask_ps(_mm_castsi128_ps(cmp)))        // MOVMSKPS
			{
				// We found 1 (or more) matches of this (pnum) pattern in this (pp to pp+15) chunk
				// Now we need to check if any match meets the length requirements
				const unsigned char * pmatch, * ppat;

				// Check each match (indicated by the bottom 4 bits of which_dword)
				for (int which = 0; which < 4; ++which, which_dword >>= 1)
				{
					if ((which_dword & 0x1) == 0)
						continue;

					// Get address of the dword we matched
					pmatch = (const unsigned char *)pp + which*4;
					ppat = to_find + pnum;

					// Scan backwards from match since we can be up to 3 bytes past where the bytes are actually the same
					for (int ii = 0; ii < 3; ++ii)
					{
						if (pmatch <= buf || ppat <= to_find - max_back || *(pmatch-1) != *(ppat-1))
							break;
						pmatch--;
						ppat--;
					}

					if ((to_find + max_forw) - ppat < min_match)
						continue;       // not enough bytes to compare

					if (memcmp(pmatch, ppat, min_match) != 0)
						continue;       // difference found before match length

					// We found a match! Now check if it is before any previously found match in this chunk
					if (retval == NULL || pmatch < retval)
					{
						retval = pmatch;
						ret_offset = ppat - to_find;
					}
				}
			}
		}

		if (retval != NULL)
			break;                                          // stop searching when we found a long enough match
	}

	// If buflen is not multiple of 16 we need to check the bit past the last "chunk" without using SSE2
	size_t len = (buf + buflen) - (unsigned char *)endbuf;
	if (retval == NULL && len >= min_match)
	{
		const unsigned char * pmatch, * ppat;
		for (int pnum = 0; pnum < 4; ++pnum)
		{
			pmatch = (unsigned char *)endbuf;
			for (;;)
			{
				ppat = to_find + pnum;
				pmatch = memmem(pmatch, len, ppat, min_match - 3);
				if (pmatch == NULL)
					break;  // not found

				// scan backwards up to 3 bytes for real start of match
				int ii;
				for (ii = 0; ii < 3; ++ii)
				{
					if (pmatch <= buf || ppat <= to_find - max_back || *(pmatch-1) != *(ppat-1))
						break;
					pmatch--;
					ppat--;
				}

				// Check we have enough matching bytes
				if (memcmp(pmatch, ppat, min_match) == 0)
				{
					if (retval == NULL || pmatch < retval)
					{
						retval = pmatch;
						ret_offset = ppat - to_find;
					}
					break;
				}
				pmatch += ii + 1;    // skip past this (too short) match
			} // for (;;)
		}
	}

	//t.stop();
	//printf("%g  %d\n", (double)t.elapsed(), (int)ret_offset);
	assert(retval == NULL || retval < buf + buflen);
	return retval;
}