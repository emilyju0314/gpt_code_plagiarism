TEST_F(MemoryHeapTest, AllocatedTooBigMemoryFailed) {
  // fully allocate memory
  auto ptr1 = memory_.allocate(memory_size_);
  // check that ptr1 is not -1, thus memory was allocated
  ASSERT_NE(ptr1, -1);

  // The memory size that can be allocated is within interval (0, kMaxMemorySize
  // - memory_size_]. Trying to allocate more
  auto big_memory_size = WasmMemoryImpl::kMaxMemorySize - memory_size_ + 1;
  ASSERT_EQ(memory_.allocate(big_memory_size), 0);
}