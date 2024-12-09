__attribute__((no_sanitize("all"))) static void PrefaultPages(uintptr_t start, uintptr_t end) {
  while (start < end) {
    auto ptr = reinterpret_cast<volatile uintptr_t *>(start);
    *ptr = *ptr;
    start += kPageSize;
  }
}