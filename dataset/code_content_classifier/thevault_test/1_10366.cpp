TEST_F(ImageSearchIndexTest, TdfIdfCosineTest) {
  AddSimpleDoc(2, -1, 4, -1, -1, "A");
  AddSimpleDoc(-1, 3, -1, -1, -1, "B");
  AddSimpleDoc(-1, -1, 10, -1, -1, "C");

  index->BuildIndex();
  SearchWithDoc(1, 4, -1, -1, -1);

  // Expected values calculated by hand
  EXPECT_EQ(2u, results.size());
  EXPECT_NEAR(results[0].score(), 0.9701, 1e-4);
  EXPECT_EQ(results[0].doc()->label(), "B");
  EXPECT_NEAR(results[1].score(), 0.1951, 1e-4);
  EXPECT_EQ(results[1].doc()->label(), "A");
}