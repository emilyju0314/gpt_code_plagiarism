TEST_F(LayoutTest, ArraySizeTest) {
  int size = 0;
  for (size = 0; kPolyBlockNames[size][0] != '\0'; ++size) {
    ;
  }
  EXPECT_EQ(size, PT_COUNT);
}