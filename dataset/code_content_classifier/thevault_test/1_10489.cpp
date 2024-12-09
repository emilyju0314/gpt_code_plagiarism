TEST_F(IndexMapBiDiTest, ManyToOne) {
  // Test the example in the comment on CompleteMerges.
  IndexMapBiDi map;
  map.Init(13, false);
  map.SetMap(2, true);
  map.SetMap(4, true);
  map.SetMap(7, true);
  map.SetMap(9, true);
  map.SetMap(11, true);
  map.Setup();
  map.Merge(map.SparseToCompact(2), map.SparseToCompact(9));
  map.Merge(map.SparseToCompact(4), map.SparseToCompact(11));
  map.CompleteMerges();
  EXPECT_EQ(3, map.CompactSize());
  EXPECT_EQ(13, map.SparseSize());
  EXPECT_EQ(1, map.SparseToCompact(4));
  EXPECT_EQ(4, map.CompactToSparse(1));
  EXPECT_EQ(1, map.SparseToCompact(11));
}