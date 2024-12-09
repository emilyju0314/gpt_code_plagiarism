struct etna_bo* etna_bo_new(void* dev, uint32_t size, uint32_t flags) {
  DLOG("bo new size %u flags 0x%x", size, flags);
  auto etna_buffer = std::make_unique<TestMsdVslDevice::EtnaBuffer>();

  etna_buffer->buffer = magma::PlatformBuffer::Create(size, "EtnaBuffer");
  if (!etna_buffer->buffer)
    return DRETP(nullptr, "failed to alloc buffer size %u", size);

  if (flags & DRM_ETNA_GEM_CACHE_UNCACHED)
    etna_buffer->buffer->SetCachePolicy(MAGMA_CACHE_POLICY_WRITE_COMBINING);

  auto etna_device = static_cast<TestMsdVslDevice::EtnaDevice*>(dev);
  uint32_t page_count = etna_buffer->buffer->size() / PAGE_SIZE;

  etna_buffer->bus_mapping =
      etna_device->test->GetBusMapper()->MapPageRangeBus(etna_buffer->buffer.get(), 0, page_count);
  if (!etna_buffer->bus_mapping)
    return DRETP(nullptr, "failed to bus map buffer");

  etna_buffer->gpu_addr = etna_device->test->next_gpu_addr(etna_buffer->buffer->size());

  if (!etna_device->test->address_space()->Insert(etna_buffer->gpu_addr,
                                                  etna_buffer->bus_mapping.get()))
    return DRETP(nullptr, "couldn't insert into address space");

  return etna_buffer.release();
}