size_t FindFirstSame(const unsigned char * buf1, const unsigned char * buf2, size_t buflen)
{
	assert((int)buf1 % SZCHK == (int)buf2 % SZCHK);         // ensure same memory alignment

	// Work out where to start the SSE2 compare by rounding up to next 16-byte memory chunk
	__m128i * pchunk1 = (__m128i *)((((int)buf1 + SZCHK-1)/SZCHK)*SZCHK);
	assert((int)pchunk1 % SZCHK == 0);

	const unsigned char * p1, * p2;
	const unsigned char * pend = (const unsigned char *)pchunk1;
	if (pend > buf1 + buflen)
		pend = buf1 + buflen;

	// Check up to 15 bytes before the first 16-byte aligned chunk
	for (p1 = buf1, p2 = buf2; p1 < pend; ++p1, ++p2)
	{
		if (*p1 == *p2)
			return p1 - buf1;
	}

	__m128i * pchunk2 = (__m128i *)((((int)buf2 + SZCHK-1)/SZCHK)*SZCHK);
	assert((int)pchunk2 % SZCHK == 0);

	pend = buf1 + buflen;

	__m128i cmp;                                                // holds result of comparing 16 bytes where each DWORD is either all bits on or off

	for ( ; (const unsigned char *)pchunk1 < pend - SZCHK; ++pchunk1, ++pchunk2)
	{
		cmp = _mm_cmpeq_epi8(*pchunk1, *pchunk2);               // PCMPEQB
		if (_mm_movemask_epi8(cmp) != 0)                        // PMOVMSKB
		{
			// There is at least one difference in the 16 bytes - find the first diff. byte
			for (p1 = (const unsigned char *)pchunk1, p2 = (const unsigned char *)pchunk2; *p1 != *p2; ++p1, ++p2)
			{
				; // nothing required in the loop body
			}
			assert(p1 - (const unsigned char *)pchunk1 < SZCHK); // else we have done something wrong (or PCMPEQD did not work)
			return p1 - buf1;
		}
	}

	// Check up to 15 bytes past the last 16-byte aligned chunk
	for (p1 = (const unsigned char *)pchunk1, p2 = (const unsigned char *)pchunk2; p1 < pend; ++p1, ++p2)
	{
		if (*p1 == *p2)
			return p1 - buf1;
	}

	return buflen;
}