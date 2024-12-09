TEST_F(HeapTest, PopWorstTest) {
  GenericHeap<IntKDPair> heap;
  KDVector v;
  // Push the test data onto both the heap and the KDVector.
  PushTestData(&heap, &v);
  // Get the worst element off the heap.
  IntKDPair pair;
  heap.PopWorst(&pair);
  EXPECT_EQ(pair.key(), 65536);
  EXPECT_EQ(pair.data(), 6);
  // Sort and remove the worst element from the vector.
  std::sort(v.begin(), v.end());
  v.resize(v.size() - 1);
  // After that they should still match!
  VerifyHeapVectorMatch(&heap, &v);
}