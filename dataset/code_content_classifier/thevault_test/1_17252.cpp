TEST(MetroHashTest, StdSet) {
  std::set<Hash> hashes;
  Hash a = {};
  hashes.insert(a);
  Hash b = {};
  b.dwords[1] = 5;
  hashes.insert(b);
  EXPECT_EQ(hashes.size(), 2u);
  Hash c = {};
  c.dwords[2] = 4;
  hashes.insert(c);
  EXPECT_EQ(hashes.size(), 3u);
  EXPECT_THAT(hashes, UnorderedElementsAre(a, b, c));

  // Insert a duplicate value.
  hashes.insert({});
  EXPECT_EQ(hashes.size(), 3u);
  EXPECT_THAT(hashes, UnorderedElementsAre(a, b, c));
}