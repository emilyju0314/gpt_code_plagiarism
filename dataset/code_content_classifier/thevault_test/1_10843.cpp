static void Expect352(int font_id, const Shape &shape) {
  EXPECT_EQ(3, shape.size());
  EXPECT_TRUE(shape.ContainsUnichar(2));
  EXPECT_TRUE(shape.ContainsUnichar(3));
  EXPECT_TRUE(shape.ContainsUnichar(5));
  EXPECT_FALSE(shape.ContainsUnichar(1));
  EXPECT_TRUE(shape.ContainsUnicharAndFont(2, font_id));
  EXPECT_FALSE(shape.ContainsUnicharAndFont(2, font_id - 1));
  EXPECT_FALSE(shape.ContainsUnicharAndFont(font_id, 2));
  // It should be a subset of itself.
  EXPECT_TRUE(shape.IsSubsetOf(shape));
}