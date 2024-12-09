TEST(MetroHashTest, Comparisons) {
  Hash a = {};
  Hash b = {};
  EXPECT_EQ(a, b);
  EXPECT_EQ(b, a);

  b.qwords[0] = 1;
  EXPECT_EQ(b, b);
  EXPECT_NE(a, b);
  EXPECT_NE(b, a);
  EXPECT_LT(a, b);

  Hash c = {};
  c.qwords[1] = 2;
  EXPECT_NE(a, c);
  EXPECT_NE(b, c);
  EXPECT_LT(a, c);
}