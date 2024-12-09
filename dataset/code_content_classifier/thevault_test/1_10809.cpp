TEST_F(NthItemTest, UniqueTest) {
  KDVector v;
  // Push the test data onto the KDVector.
  PushTestData(&v);
  // Get the median item.
  size_t index = v.size() / 2;
  std::nth_element(v.begin(), v.begin() + index, v.end());
  // The result is 6, it started out at index 11.
  EXPECT_EQ(6, v[index].key());
  EXPECT_EQ(11, v[index].data());
}