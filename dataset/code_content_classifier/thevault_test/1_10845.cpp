TEST_F(ShapeTest, AddShapeTest) {
#ifdef DISABLED_LEGACY_ENGINE
  // Skip test because Shape is missing.
  GTEST_SKIP();
#else
  Shape shape1;
  Setup352(101, &shape1);
  Expect352(101, shape1);
  // Now setup a different shape with different content.
  Shape shape2;
  shape2.AddToShape(3, 101); // Duplicates shape1.
  shape2.AddToShape(5, 110); // Different font to shape1.
  shape2.AddToShape(7, 101); // Different unichar to shape1.
  // They should NOT be subsets of each other.
  EXPECT_FALSE(shape1.IsSubsetOf(shape2));
  EXPECT_FALSE(shape2.IsSubsetOf(shape1));
  // Now add shape2 to shape1.
  shape1.AddShape(shape2);
  // Test subsets again.
  EXPECT_FALSE(shape1.IsSubsetOf(shape2));
  EXPECT_TRUE(shape2.IsSubsetOf(shape1));
  EXPECT_EQ(4, shape1.size());
  EXPECT_FALSE(shape1.ContainsUnichar(1));
  EXPECT_TRUE(shape1.ContainsUnicharAndFont(5, 101));
  EXPECT_TRUE(shape1.ContainsUnicharAndFont(5, 110));
  EXPECT_FALSE(shape1.ContainsUnicharAndFont(3, 110));
  EXPECT_FALSE(shape1.ContainsUnicharAndFont(7, 110));
  EXPECT_FALSE(shape1.IsEqualUnichars(&shape2));
#endif
}