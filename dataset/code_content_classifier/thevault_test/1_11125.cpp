TEST_F(ResultIteratorTest, ComplexTest) {
  SetImage("8087_054.3B.tif");
  // Just run layout analysis.
  PageIterator *it = api_.AnalyseLayout();
  EXPECT_FALSE(it == nullptr);
  // The images should rebuild almost perfectly.
  VerifyRebuilds(2073, 2073, 2080, 2081, 2090, it);
  delete it;
}