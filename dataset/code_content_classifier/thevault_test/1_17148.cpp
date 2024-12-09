TEST_F(QuicIntervalDequeTest, OffByOne) {
  // The write index should point to the beginning of the container.
  const int32_t cached_index = QuicIntervalDequePeer::GetCachedIndex(&qid_);
  EXPECT_EQ(cached_index, 0);

  auto it = qid_.DataBegin();
  auto end = qid_.DataEnd();
  for (int32_t i = 0; i < kSize - 1; ++i, ++it) {
    EXPECT_EQ(it->val, i);
    const int32_t off_by_one_i = i + 1;
    const std::size_t current_iteraval_begin = off_by_one_i * kIntervalStep;
    // Make sure the index has changed just from using |DataAt|
    const int32_t index_before = QuicIntervalDequePeer::GetCachedIndex(&qid_);
    EXPECT_EQ(index_before, i);
    // The |DataAt| method should find the correct interval.
    auto lookup = qid_.DataAt(current_iteraval_begin);
    EXPECT_EQ(off_by_one_i, lookup->val);
    // Check that the index has changed.
    const int32_t index_after = QuicIntervalDequePeer::GetCachedIndex(&qid_);
    const int32_t after_i = off_by_one_i == kSize ? -1 : off_by_one_i;
    EXPECT_EQ(index_after, after_i);
    EXPECT_NE(it, end);
  }
}