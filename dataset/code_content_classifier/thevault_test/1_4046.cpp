void recordQueue(const c10::DataPtr& data_ptr, Queue queue) {
  if (debug_mode) {
    debugging_allocator.recordQueue(data_ptr, queue);
  } else {
    caching_allocator.recordQueue(data_ptr, queue);
  }
}