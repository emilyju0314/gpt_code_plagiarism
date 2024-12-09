inline size_t align(size_t sz, size_t alignment) noexcept
  {
    ::gsl::narrow<ptrdiff_t>(sz);
    ::gsl::narrow<ptrdiff_t>(alignment);
    return ::gsl::narrow<size_t>(((sz + alignment - 1) / alignment) * alignment);
  }