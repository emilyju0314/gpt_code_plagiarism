uint64_t currentMemoryAllocated(int device_id) {
  retriveDebugFlag();
  if (debug_mode) {
    return debugging_allocator.get_memory_stats_for_device(device_id).allocated_size;
  } else {
    return caching_allocator.get_memory_stats_for_device(device_id).allocated_size;
  }
}