TEST_F(MemoryHeapTest, ResetTest) {
  const size_t N = 42;
  ASSERT_EQ(memory_.allocate(N), 1);
  memory_.reset();
  ASSERT_EQ(memory_.allocate(N), 1);
}