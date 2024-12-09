TEST_F(QuicIntervalDequeTest, IteratorInvalidation) {
  // The write index should point to the beginning of the container.
  const int32_t cached_index = QuicIntervalDequePeer::GetCachedIndex(&qid_);
  EXPECT_EQ(cached_index, 0);

  const std::size_t iteraval_begin = (kSize - 1) * kIntervalStep;
  auto lookup = qid_.DataAt(iteraval_begin);
  EXPECT_EQ((*lookup).val, (kSize - 1));
  qid_.PopFront();
  EXPECT_QUIC_BUG(lookup++, "Iterator out of bounds.");
  auto lookup_end = qid_.DataAt(iteraval_begin + kIntervalStep);
  EXPECT_EQ(lookup_end, qid_.DataEnd());
}