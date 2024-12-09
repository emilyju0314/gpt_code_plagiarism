TEST_F(IndexMapBiDiTest, Primes) {
  IndexMapBiDi map;
  ComputePrimes(&map);
  TestPrimes(map);
  // It still works if we assign it to another.
  IndexMapBiDi map2;
  map2.CopyFrom(map);
  TestPrimes(map2);
  // Or if we assign it to a base class.
  IndexMap base_map;
  base_map.CopyFrom(map);
  TestPrimes(base_map);
  // Test file i/o too.
  std::string filename = OutputNameToPath("primesmap");
  FILE *fp = fopen(filename.c_str(), "wb");
  CHECK(fp != nullptr);
  EXPECT_TRUE(map.Serialize(fp));
  fclose(fp);
  fp = fopen(filename.c_str(), "rb");
  CHECK(fp != nullptr);
  IndexMapBiDi read_map;
  EXPECT_TRUE(read_map.DeSerialize(false, fp));
  fclose(fp);
  TestPrimes(read_map);
}