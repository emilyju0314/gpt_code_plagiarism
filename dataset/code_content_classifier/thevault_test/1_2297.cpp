static void PrefaultStackPages() {
  pthread_attr_t attr;
  ASSERT_EQ(pthread_getattr_np(pthread_self(), &attr), 0);

  void *stackaddr;
  size_t stacksize;
  ASSERT_EQ(pthread_attr_getstack(&attr, &stackaddr, &stacksize), 0);

  uintptr_t stackstart = reinterpret_cast<uintptr_t>(stackaddr);
  uintptr_t stackend = reinterpret_cast<uintptr_t>(stackaddr) + stacksize;

  // Prefault all stack pages to make sure this doesn't happen later while
  // collecting samples.
  PrefaultPages(stackstart, stackend);
  // We also need to prefault all stack shadow pages.
  size_t shadow_scale;
  size_t shadow_offset;
  __asan_get_shadow_mapping(&shadow_scale, &shadow_offset);
  PrefaultPages((stackstart >> shadow_scale) + shadow_offset,
                (stackend >> shadow_scale) + shadow_offset);
}