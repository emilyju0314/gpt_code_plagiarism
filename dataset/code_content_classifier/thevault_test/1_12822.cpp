inline size_t align(size_t size) noexcept
  {
    ::gsl::narrow<ptrdiff_t>(size);
    return ((size + c_alignment - 1) >> c_align_pow2) << c_align_pow2;
  }