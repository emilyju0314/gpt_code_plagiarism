uint64_t currentMemoryCached(int device_id) {
  retriveDebugFlag();
  if (debug_mode) {
    return debugging_allocator.get_memory_stats_for_device(device_id).cached_size;
  } else {
    return caching_allocator.get_memory_stats_for_device(device_id).cached_size;
  }
}