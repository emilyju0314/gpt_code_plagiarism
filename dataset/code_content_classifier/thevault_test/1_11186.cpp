TEST_F(BitVectorTest, Primes) {
  BitVector map;
  ComputePrimes(&map);
  TestPrimes(map);
  // It still works if we use the copy constructor.
  BitVector map2(map);
  TestPrimes(map2);
  // Or if we assign it.
  BitVector map3;
  map3 = map;
  TestPrimes(map3);
  // Test file i/o too.
  std::string filename = OutputNameToPath("primesbitvector");
  FILE *fp = fopen(filename.c_str(), "wb");
  ASSERT_TRUE(fp != nullptr);
  EXPECT_TRUE(map.Serialize(fp));
  fclose(fp);
  fp = fopen(filename.c_str(), "rb");
  ASSERT_TRUE(fp != nullptr);
  BitVector read_map;
  EXPECT_TRUE(read_map.DeSerialize(false, fp));
  fclose(fp);
  TestPrimes(read_map);
}