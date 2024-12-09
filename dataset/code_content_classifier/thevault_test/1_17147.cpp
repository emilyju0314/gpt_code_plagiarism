TEST_F(QuicIntervalDequeTest, InsertIterateWhole) {
  // The write index should point to the beginning of the container.
  const int32_t cached_index = QuicIntervalDequePeer::GetCachedIndex(&qid_);
  EXPECT_EQ(cached_index, 0);

  auto it = qid_.DataBegin();
  auto end = qid_.DataEnd();
  for (int32_t i = 0; i < kSize; ++i, ++it) {
    EXPECT_EQ(it->val, i);
    const std::size_t current_iteraval_begin = i * kIntervalStep;
    // The |DataAt| method should find the correct interval.
    auto lookup = qid_.DataAt(current_iteraval_begin);
    EXPECT_EQ(i, lookup->val);
    // Make sure the index hasn't changed just from using |DataAt|
    const int32_t index_before = QuicIntervalDequePeer::GetCachedIndex(&qid_);
    EXPECT_EQ(index_before, i);
    // This increment should move the index forward.
    lookup++;
    // Check that the index has changed.
    const int32_t index_after = QuicIntervalDequePeer::GetCachedIndex(&qid_);
    const int32_t after_i = (i + 1) == kSize ? -1 : (i + 1);
    EXPECT_EQ(index_after, after_i);
    EXPECT_NE(it, end);
  }
}