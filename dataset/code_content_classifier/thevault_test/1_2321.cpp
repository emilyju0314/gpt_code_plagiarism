bool MsdVslDevice::SubmitCommandBuffer(std::shared_ptr<AddressSpace> address_space,
                                       magma::PlatformBuffer* buf, uint32_t gpu_addr,
                                       uint32_t length, uint16_t* prefetch_out) {
  if (!InitRingbuffer(address_space)) {
    return DRETF(false, "Error initializing ringbuffer");
  }
  uint64_t rb_gpu_addr;
  bool res = ringbuffer_->GetGpuAddress(&rb_gpu_addr);
  if (!res) {
    return DRETF(false, "Failed to get ringbuffer gpu address");
  }
  length = magma::round_up(length, sizeof(uint64_t));

  // Number of new commands to be added to the ringbuffer. This should be changed once we add
  // more than just WAIT-LINK.
  const uint16_t kRbPrefetch = 2;

  // Write a LINK at the end of the command buffer that links back to the ringbuffer.
  if (!WriteLinkCommand(buf, length, kRbPrefetch,
                        static_cast<uint32_t>(rb_gpu_addr + ringbuffer_->tail()))) {
    return DRETF(false, "Failed to write LINK from command buffer to ringbuffer");
  }
  // Increment the command buffer length to account for the LINK command size.
  length += (kInstructionDwords * sizeof(uint32_t));

  uint32_t prefetch = magma::round_up(length, sizeof(uint64_t)) / sizeof(uint64_t);
  if (prefetch & 0xFFFF0000)
    return DRETF(false, "Can't submit length %u (prefetch 0x%x)", length, prefetch);

  *prefetch_out = prefetch & 0xFFFF;

  // Add a new WAIT-LINK to the end of the ringbuffer.
  if (!AddRingbufferWaitLink()) {
    return DRETF(false, "Failed to add WAIT-LINK to ringbuffer");
  }

  DLOG("Submitting buffer at gpu addr 0x%x", gpu_addr);

  if (!LinkRingbuffer(kRbPrefetch, gpu_addr, *prefetch_out)) {
    return DRETF(false, "Failed to link ringbuffer");
  }
  return true;
}