TEST_F(MemoryHeapTest, AllocateAfterDeallocate) {
  // two memory sizes totalling to the total memory size
  const size_t size1 = 2045;
  const size_t size2 = 2049;

  // allocate two memory chunks with total size equal to the memory size
  auto ptr1 = memory_.allocate(size1);
  memory_.allocate(size2);

  // deallocate first memory chunk
  memory_.deallocate(ptr1);

  // allocate new memory chunk
  auto ptr1_1 = memory_.allocate(size1);
  // expected that it will be allocated on the same place as the first memory
  // chunk that was deallocated
  ASSERT_EQ(ptr1, ptr1_1);
}