TEST(MetroHashTest, CompactZero) {
  Hash hash = {};
  EXPECT_EQ(std::hash<Hash>{}(hash), 0u);

  hash.qwords[0] = 42;
  EXPECT_NE(std::hash<Hash>{}(hash), 0u);
}