void emptyCachedMem() {
  retriveDebugFlag();
  if (debug_mode) {
    return debugging_allocator.emptyCached();
  } else {
    return caching_allocator.emptyCached();
  }
}