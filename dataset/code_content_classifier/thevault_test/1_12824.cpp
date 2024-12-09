inline void secure_zero_no_vector(volatile void *s, size_t in_n)
    {
      auto n = ::gsl::narrow<ptrdiff_t>(in_n);
      auto *p_sz = reinterpret_cast<volatile size_t *>(s);
      while (n >= ::gsl::narrow_cast<ptrdiff_t>(sizeof(size_t))) {
#ifdef __SSE__
        _mm_stream_pi(reinterpret_cast<__m64 *>(const_cast<size_t *>(p_sz)), __m64{0});
        p_sz++;
#else
        *p_sz++ = 0;
#endif
        n -= sizeof(size_t);
      }
      auto p = reinterpret_cast<volatile char *>(p_sz);

      while ((n--) != 0) {
        *p++ = 0;
      }
    }