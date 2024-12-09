inline static void mm_recursion(__m128i * r, __m128i a, __m128i b,
		__m128i c, __m128i d)
	{
		__m128i v, x, y, z;

		y = _mm_srli_epi32(b, SFMT_SR1);
		z = _mm_srli_si128(c, SFMT_SR2);
		v = _mm_slli_epi32(d, SFMT_SL1);
		z = _mm_xor_si128(z, a);
		z = _mm_xor_si128(z, v);
		x = _mm_slli_si128(a, SFMT_SL2);
		y = _mm_and_si128(y, sse2_param_mask.si);
		z = _mm_xor_si128(z, x);
		z = _mm_xor_si128(z, y);
		*r = z;
	}