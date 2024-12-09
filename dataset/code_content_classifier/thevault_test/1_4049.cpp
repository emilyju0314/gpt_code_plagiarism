uint64_t maxMemoryAllocated(int device_id) {
  retriveDebugFlag();
  if (debug_mode) {
    return debugging_allocator.get_memory_stats_for_device(device_id).max_allocated_size;
  } else {
    return caching_allocator.get_memory_stats_for_device(device_id).max_allocated_size;
  }
}