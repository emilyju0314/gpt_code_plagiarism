TEST_F(MemoryHeapTest, LoadNTest) {
  const size_t N = 3;

  sgns::base::Buffer b(N, 'c');

  auto ptr = memory_.allocate(N);

  memory_.storeBuffer(ptr, b);

  auto res_b = memory_.loadN(ptr, N);
  ASSERT_EQ(b, res_b);
}