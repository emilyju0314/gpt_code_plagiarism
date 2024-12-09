TEST_F(QuicIntervalDequeTest, RescanData) {
  // The write index should point to the beginning of the container.
  const int32_t index = QuicIntervalDequePeer::GetCachedIndex(&qid_);
  EXPECT_EQ(index, 0);

  auto it = qid_.DataBegin();
  auto end = qid_.DataEnd();
  for (int32_t i = 0; i < kSize - 1; ++i, ++it) {
    EXPECT_EQ(it->val, i);
    const std::size_t current_iteraval_begin = i * kIntervalStep;
    // The |DataAt| method should find the correct interval.
    auto lookup = qid_.DataAt(current_iteraval_begin);
    EXPECT_EQ(i, lookup->val);
    // Make sure the index has changed just from using |DataAt|
    const int32_t cached_index_before =
        QuicIntervalDequePeer::GetCachedIndex(&qid_);
    EXPECT_EQ(cached_index_before, i);
    // Ensure the real index has changed just from using |DataAt| and the
    // off-by-one logic
    const int32_t index_before = QuicIntervalDequePeer::GetCachedIndex(&qid_);
    const int32_t before_i = i;
    EXPECT_EQ(index_before, before_i);
    // This increment should move the cached index forward.
    lookup++;
    // Check that the cached index has moved foward.
    const int32_t cached_index_after =
        QuicIntervalDequePeer::GetCachedIndex(&qid_);
    const int32_t after_i = (i + 1);
    EXPECT_EQ(cached_index_after, after_i);
    EXPECT_NE(it, end);
  }

  // Iterate over items which have been consumed before.
  int32_t expected_index = static_cast<int32_t>(kSize - 1);
  for (int32_t i = 0; i < kSize - 1; ++i) {
    const std::size_t current_iteraval_begin = i * kIntervalStep;
    // The |DataAt| method should find the correct interval.
    auto lookup = qid_.DataAt(current_iteraval_begin);
    EXPECT_EQ(i, lookup->val);
    // This increment shouldn't move the index forward as the index is currently
    // ahead.
    lookup++;
    // Check that the index hasn't moved foward.
    const int32_t index_after = QuicIntervalDequePeer::GetCachedIndex(&qid_);
    EXPECT_EQ(index_after, expected_index);
    EXPECT_NE(it, end);
  }
}