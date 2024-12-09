TEST_F(MemoryHeapTest, DeallocateNonexistingMemoryChunk) {
  const size_t size1 = 2047;

  memory_.allocate(size1);

  auto ptr_to_nonexisting_chunk = 2;
  auto opt_deallocated_size = memory_.deallocate(ptr_to_nonexisting_chunk);
  ASSERT_FALSE(opt_deallocated_size.has_value());
}