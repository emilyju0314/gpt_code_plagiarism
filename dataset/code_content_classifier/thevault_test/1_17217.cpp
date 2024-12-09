TEST_F(IoTest, LargeOutput) {
  std::string str;
  StringOutputStream output(&str);
  void* unused_data;
  int size;
  // Repeatedly calling Next should eventually grow the buffer to kint32max.
  do {
    EXPECT_TRUE(output.Next(&unused_data, &size));
  } while (str.size() < std::numeric_limits<int>::max());
  // Further increases should be possible.
  output.Next(&unused_data, &size);
  EXPECT_GT(size, 0);
}