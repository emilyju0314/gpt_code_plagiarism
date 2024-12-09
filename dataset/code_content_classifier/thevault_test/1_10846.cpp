TEST_F(ShapeTableTest, FullTest) {
#ifdef DISABLED_LEGACY_ENGINE
  // Skip test because Shape is missing.
  GTEST_SKIP();
#else
  Shape shape1;
  Setup352(101, &shape1);
  // Build a shape table with the same data, but in separate shapes.
  UNICHARSET unicharset;
  unicharset.unichar_insert(" ");
  for (int i = 1; i <= 10; ++i) {
    char class_str[20];
    snprintf(class_str, sizeof(class_str), "class%d", i);
    unicharset.unichar_insert(class_str);
  }
  ShapeTable st(unicharset);
  EXPECT_EQ(0, st.AddShape(3, 101));
  EXPECT_EQ(1, st.AddShape(5, 101));
  EXPECT_EQ(2, st.AddShape(2, 101));
  EXPECT_EQ(3, st.NumShapes());
  Expect352(101, shape1);
  EXPECT_EQ(3, st.AddShape(shape1));
  for (int i = 0; i < 3; ++i) {
    EXPECT_FALSE(st.MutableShape(i)->IsEqualUnichars(&shape1));
  }
  EXPECT_TRUE(st.MutableShape(3)->IsEqualUnichars(&shape1));
  EXPECT_TRUE(st.AnyMultipleUnichars());
  st.DeleteShape(3);
  EXPECT_FALSE(st.AnyMultipleUnichars());

  // Now merge to make a single shape like shape1.
  EXPECT_EQ(1, st.MasterUnicharCount(0));
  st.MergeShapes(0, 1);
  EXPECT_EQ(3, st.MergedUnicharCount(1, 2));
  st.MergeShapes(1, 2);
  for (int i = 0; i < 3; ++i) {
    EXPECT_EQ(3, st.MasterUnicharCount(i));
    // Master font count is the sum of all the font counts in the shape, not
    // the actual number of different fonts in the shape.
    EXPECT_EQ(3, st.MasterFontCount(i));
  }
  EXPECT_EQ(0, st.MasterDestinationIndex(1));
  EXPECT_EQ(0, st.MasterDestinationIndex(2));
  ShapeTable st2;
  st2.AppendMasterShapes(st, nullptr);
  EXPECT_EQ(1, st.NumMasterShapes());
  EXPECT_EQ(1, st2.NumShapes());
  EXPECT_TRUE(st2.MutableShape(0)->IsEqualUnichars(&shape1));
  EXPECT_TRUE(st2.AnyMultipleUnichars());
#endif
}