inline void secure_zero(void *s, size_t n)
  {
#if defined(__AVX__) && !defined(__APPLE__)
    __m256i zero256 = _mm256_setzero_si256();
    auto p_m256 = reinterpret_cast<volatile __m256i *>(s);
    auto p_m128 = reinterpret_cast<volatile __m128i *>(p_m256);
    if (!s % 32) {
      while (n >= sizeof(__m256i)) {
        *p_m256++ = zero256;
        n -= sizeof(__m256i);
      }
      p_m128 = reinterpret_cast<volatile __m128i *>(p_m256);
      if (n >= sizeof(__m128i)) {
        *p_m128++ = _mm_setzero_si128();
        n -= sizeof(__m128i);
      }
    }
    auto p_sz = reinterpret_cast<volatile size_t *>(p_m128);
#elif defined(__SSE2__)
    const __m128i zero = _mm_setzero_si128();
    auto p_m128 = reinterpret_cast<volatile __m128i *>(s);
    if ((reinterpret_cast<size_t>(s) % 16) == 0) {
      while (n >= sizeof(__m128i)) {
        *p_m128++ = zero;
        n -= sizeof(__m128i);
      }
    }
    auto p_sz = reinterpret_cast<volatile size_t *>(p_m128);
#else
    auto p_sz = reinterpret_cast<volatile size_t *>(s);
    while (n >= sizeof(size_t) * 8) {
      *p_sz++ = 0;
      *p_sz++ = 0;
      *p_sz++ = 0;
      *p_sz++ = 0;
      n -= sizeof(size_t) * 4;
    }
#endif
    details::secure_zero_no_vector(p_sz, n);
  }