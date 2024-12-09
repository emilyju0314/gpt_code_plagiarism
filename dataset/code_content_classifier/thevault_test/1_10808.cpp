TEST_F(NthItemTest, BoringTest) {
  KDVector v;
  // Push the test data onto the KDVector.
  int test_data[] = {8, 8, 8, 8, 8, 7, 7, 7, 7};
  for (size_t i = 0; i < countof(test_data); ++i) {
    IntKDPair pair(test_data[i], i);
    v.push_back(pair);
  }
  // The 3rd item is 7 but the 4th is 8..
  size_t index = 3;
  std::nth_element(v.begin(), v.begin() + index, v.end());
  // The result is 7.
  EXPECT_EQ(7, v[index].key());
  index = 4;
  std::nth_element(v.begin(), v.begin() + index, v.end());
  // The result is 8.
  EXPECT_EQ(8, v[index].key());
  // Get the min item.
  index = 0;
  std::nth_element(v.begin(), v.begin() + index, v.end());
  // The result is 7.
  EXPECT_EQ(7, v[index].key());
  // Get the max item.
  index = v.size() - 1;
  std::nth_element(v.begin(), v.begin() + index, v.end());
  // The result is 8.
  EXPECT_EQ(8, v[index].key());
}