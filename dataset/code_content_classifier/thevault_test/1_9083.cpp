TEST_F(MemoryHeapTest, AllocateTooBigMemoryAfterDeallocate) {
  // two memory sizes totalling to the total memory size
  const size_t size1 = 2047;
  const size_t size2 = 2049;

  // allocate two memory chunks with total size equal to the memory size
  auto ptr1 = memory_.allocate(size1);
  auto ptr2 = memory_.allocate(size2);

  // calculate memory offset after two allocations
  auto mem_offset = ptr2 + size2;

  // deallocate first memory chunk
  memory_.deallocate(ptr1);

  // allocate new memory chunk with bigger size than the space left in the
  // memory
  auto ptr3 = memory_.allocate(size1 + 1);

  // memory is allocated on mem offset
  ASSERT_EQ(ptr3, mem_offset);
}