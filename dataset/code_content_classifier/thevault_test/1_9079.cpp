TEST_F(MemoryHeapTest, ReturnOffsetWhenAllocated) {
  const size_t size1 = 2049;
  const size_t size2 = 2045;

  // allocate memory of size 1
  auto ptr1 = memory_.allocate(size1);
  // first memory chunk is always allocated at 1
  ASSERT_EQ(ptr1, 1);

  // allocated second memory chunk
  auto ptr2 = memory_.allocate(size2);
  // second memory chunk is placed right after the first one
  ASSERT_EQ(ptr2, size1 + ptr1);
}