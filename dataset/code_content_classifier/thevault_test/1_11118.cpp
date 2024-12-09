TEST_F(HeapTest, SortTest) {
  GenericHeap<IntKDPair> heap;
  EXPECT_TRUE(heap.empty());
  KDVector v;
  EXPECT_EQ(heap.size(), v.size());
  // Push the test data onto both the heap and the KDVector.
  PushTestData(&heap, &v);
  VerifyHeapVectorMatch(&heap, &v);
}