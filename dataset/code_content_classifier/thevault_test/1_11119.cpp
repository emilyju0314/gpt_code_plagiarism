TEST_F(HeapTest, MixedTest) {
  GenericHeap<IntKDPair> heap;
  KDVector v;
  // Push the test data onto both the heap and the KDVector.
  PushTestData(&heap, &v);
  // Sort the vector and remove the first 5 values from both heap and v.
  std::sort(v.begin(), v.end());
  for (int i = 0; i < 5; ++i) {
    heap.Pop(nullptr);
    v.erase(v.begin());
  }
  // Push the test data onto both the heap and the KDVector.
  PushTestData(&heap, &v);
  // Heap and vector should still match!
  VerifyHeapVectorMatch(&heap, &v);
}