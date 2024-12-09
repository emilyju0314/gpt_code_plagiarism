TEST(EltwiseReduceMod, AVX512Big_0_1) {
  std::random_device rd;
  std::mt19937 gen(rd());

  size_t length = 1024;

  for (size_t bits = 50; bits <= 62; ++bits) {
    uint64_t modulus = GeneratePrimes(1, bits, length)[0];
    std::uniform_int_distribution<uint64_t> distrib(0, modulus - 1);

#ifdef HEXL_DEBUG
    size_t num_trials = 10;
#else
    size_t num_trials = 100;
#endif
    for (size_t trial = 0; trial < num_trials; ++trial) {
      std::vector<uint64_t> op1(length, 0);
      for (size_t i = 0; i < length; ++i) {
        op1[i] = distrib(gen);
      }
      std::vector<uint64_t> result1(length, 0);
      std::vector<uint64_t> result2(length, 0);
      auto op2 = op1;

      EltwiseReduceModNative(result1.data(), op1.data(), op1.size(), modulus, 0,
                             1);
      EltwiseReduceModAVX512(result2.data(), op2.data(), op1.size(), modulus, 0,
                             1);

      ASSERT_EQ(result1, result2);
      ASSERT_EQ(result1, result2);
    }
  }
}