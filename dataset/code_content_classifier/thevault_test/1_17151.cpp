TEST_F(QuicIntervalDequeTest, InsertIterateInsert) {
  // The write index should point to the beginning of the container.
  const int32_t index = QuicIntervalDequePeer::GetCachedIndex(&qid_);
  EXPECT_EQ(index, 0);

  int32_t iterated_elements = 0;
  for (int32_t i = 0; i < kSize; ++i, ++iterated_elements) {
    // Get an iterator.
    const std::size_t current_iteraval_begin = i * kIntervalStep;
    auto lookup = qid_.DataAt(current_iteraval_begin);
    const int32_t index_before = QuicIntervalDequePeer::GetCachedIndex(&qid_);
    // The index should always point to i.
    EXPECT_EQ(index_before, i);
    // This iterator increment should effect the index.
    lookup++;
    // Show the index has been updated to point to i + 1 or -1 if at the end.
    const int32_t index_after = QuicIntervalDequePeer::GetCachedIndex(&qid_);
    const int32_t after_i = (i + 1) == kSize ? -1 : (i + 1);
    EXPECT_EQ(index_after, after_i);
  }
  const int32_t invalid_index = QuicIntervalDequePeer::GetCachedIndex(&qid_);
  EXPECT_EQ(invalid_index, -1);

  // Add more data to the container, making the index valid.
  const std::size_t offset = qid_.Size();
  for (int32_t i = 0; i < kSize; ++i) {
    const std::size_t interval_begin = offset + (kIntervalStep * i);
    const std::size_t interval_end = offset + interval_begin + kIntervalStep;
    qid_.PushBack(TestIntervalItem(i + offset, interval_begin, interval_end));
    const int32_t index_current = QuicIntervalDequePeer::GetCachedIndex(&qid_);
    // Index should now be valid and equal to the size of the container before
    // adding more items to it.
    EXPECT_EQ(index_current, iterated_elements);
  }
  // Show the index is still valid and hasn't changed since the first iteration
  // of the loop.
  const int32_t index_after_add = QuicIntervalDequePeer::GetCachedIndex(&qid_);
  EXPECT_EQ(index_after_add, iterated_elements);

  // Iterate over all the data in the container and eventually reset the index
  // as we did before.
  for (int32_t i = 0; i < kSize; ++i, ++iterated_elements) {
    const std::size_t interval_begin = offset + (kIntervalStep * i);
    const int32_t index_current = QuicIntervalDequePeer::GetCachedIndex(&qid_);
    EXPECT_EQ(index_current, iterated_elements);
    auto lookup = qid_.DataAt(interval_begin);
    const int32_t expected_value = i + offset;
    EXPECT_EQ(lookup->val, expected_value);
    lookup++;
    const int32_t after_inc =
        (iterated_elements + 1) == (kSize * 2) ? -1 : (iterated_elements + 1);
    const int32_t after_index = QuicIntervalDequePeer::GetCachedIndex(&qid_);
    EXPECT_EQ(after_index, after_inc);
  }
  // Show the index is now invalid.
  const int32_t invalid_index_again =
      QuicIntervalDequePeer::GetCachedIndex(&qid_);
  EXPECT_EQ(invalid_index_again, -1);
}