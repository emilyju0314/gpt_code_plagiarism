TEST_F(NthItemTest, EqualTest) {
  KDVector v;
  // Push the test data onto the KDVector.
  PushTestData(&v);
  // Add an extra 8. This makes the median 7.
  IntKDPair pair(8, 13);
  v.push_back(pair);
  // Get the median item.
  size_t index = v.size() / 2;
  std::nth_element(v.begin(), v.begin() + index, v.end());
  // The result is 7, it started out at index 4 or 12.
  EXPECT_EQ(7, v[index].key());
  EXPECT_TRUE(v[index].data() == 4 || v[index].data() == 12);
}