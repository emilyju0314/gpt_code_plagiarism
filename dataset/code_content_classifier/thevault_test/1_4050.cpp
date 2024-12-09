uint64_t maxMemoryCached(int device_id) {
  retriveDebugFlag();
  if (debug_mode) {
    return debugging_allocator.get_memory_stats_for_device(device_id).max_cached_size;
  } else {
    return caching_allocator.get_memory_stats_for_device(device_id).max_cached_size;
  }
}