TEST_F(HeapTest, RevalueTest) {
  // Here the data element of the pair is a DoublePtr, which links the entries
  // in the vector and heap, and we test a MAX heap.
  typedef KDPairDec<int, DoublePtr> PtrPair;
  GenericHeap<PtrPair> heap;
  std::vector<PtrPair> v;
  // Push the test data onto both the heap and the vector.
  for (int i : test_data) {
    PtrPair h_pair;
    h_pair.key() = i;
    PtrPair v_pair;
    v_pair.key() = i;
    h_pair.data().Connect(&v_pair.data());
    heap.Push(&h_pair);
    v.push_back(v_pair);
  }
  // Test changes both ways. Index 0 is 8, so change it to -1.
  v[0].key() = -1;
  // v[0].data.OtherEnd() is a pointer to the data element in the appropriate
  // heap entry, wherever it may be. We can change its value via that pointer.
  // Without Reshuffle, that would be a terribly bad thing to do, as it violates
  // the heap invariant, making the heap corrupt.
  auto *pair_ptr = reinterpret_cast<PtrPair *>(v[0].data().OtherEnd());
  pair_ptr->key() = v[0].key();
  heap.Reshuffle(pair_ptr);
  // Index 1 is 1. Change to 32767.
  v[1].key() = 32767;
  pair_ptr = reinterpret_cast<PtrPair *>(v[1].data().OtherEnd());
  pair_ptr->key() = v[1].key();
  heap.Reshuffle(pair_ptr);
  // After the changes, popping the heap should still match the sorted order
  // of the vector.
  std::sort(v.begin(), v.end());
  EXPECT_GT(v[0].key(), v.back().key());
  for (auto &i : v) {
    EXPECT_EQ(i.key(), heap.PeekTop().key());
    EXPECT_FALSE(heap.empty());
    heap.Pop(nullptr);
  }
  EXPECT_TRUE(heap.empty());
}