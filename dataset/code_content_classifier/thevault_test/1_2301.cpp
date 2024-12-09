bool matches_last_wait_link(Ringbuffer* ringbuffer, uint32_t gpu_addr) {
  // The last WAIT-LINK will be between [tail - 16, tail].
  auto wait_link_start = ringbuffer->SubtractOffset(kWaitLinkDwords * sizeof(uint32_t));
  auto wait_link_end = ringbuffer->tail();

  uint64_t rb_gpu_addr;
  if (!ringbuffer->GetGpuAddress(&rb_gpu_addr)) {
    return DRETF(false, "Failed to get ringbuffer gpu addr");
  }
  // The address lies before the start of the ringbuffer.
  if (gpu_addr < rb_gpu_addr) {
    return false;
  }
  auto rb_offset = gpu_addr - rb_gpu_addr;
  if (rb_offset >= ringbuffer->size()) {
    return false;
  }
  return wait_link_start <= wait_link_end ?
      (rb_offset >= wait_link_start) && (rb_offset < wait_link_end) :
      (rb_offset >= wait_link_start) || (rb_offset < wait_link_end);
}