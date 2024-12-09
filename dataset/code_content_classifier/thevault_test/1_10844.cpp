TEST_F(ShapeTest, BasicTest) {
#ifdef DISABLED_LEGACY_ENGINE
  // Skip test because Shape is missing.
  GTEST_SKIP();
#else
  Shape shape1;
  EXPECT_EQ(0, shape1.size());
  Setup352(101, &shape1);
  Expect352(101, shape1);
  // It should still work after file I/O.
  std::string filename = TmpNameToPath("shapefile");
  FILE *fp = fopen(filename.c_str(), "wb");
  ASSERT_TRUE(fp != nullptr);
  EXPECT_TRUE(shape1.Serialize(fp));
  fclose(fp);
  TFile tfp;
  EXPECT_TRUE(tfp.Open(filename.c_str(), nullptr));
  Shape shape2;
  EXPECT_TRUE(shape2.DeSerialize(&tfp));
  Expect352(101, shape2);
  // They should be subsets of each other.
  EXPECT_TRUE(shape1.IsSubsetOf(shape2));
  EXPECT_TRUE(shape2.IsSubsetOf(shape1));
  // They should be equal unichars.
  EXPECT_TRUE(shape1.IsEqualUnichars(&shape2));
  // and still pass afterwards.
  Expect352(101, shape1);
  Expect352(101, shape2);
#endif
}