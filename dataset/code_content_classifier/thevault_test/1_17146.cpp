TEST_F(QuicIntervalDequeTest, InsertRemoveSize) {
  QID qid;

  EXPECT_EQ(qid.Size(), std::size_t(0));
  qid.PushBack(TestIntervalItem(0, 0, 10));
  EXPECT_EQ(qid.Size(), std::size_t(1));
  qid.PushBack(TestIntervalItem(1, 10, 20));
  EXPECT_EQ(qid.Size(), std::size_t(2));
  qid.PushBack(TestIntervalItem(2, 20, 30));
  EXPECT_EQ(qid.Size(), std::size_t(3));
  qid.PushBack(TestIntervalItem(3, 30, 40));
  EXPECT_EQ(qid.Size(), std::size_t(4));

  // Advance the index all the way...
  int32_t i = 0;
  for (auto it = qid.DataAt(0); it != qid.DataEnd(); ++it, ++i) {
    const int32_t index = QuicIntervalDequePeer::GetCachedIndex(&qid);
    EXPECT_EQ(index, i);
    EXPECT_EQ(it->val, i);
  }
  const int32_t index = QuicIntervalDequePeer::GetCachedIndex(&qid);
  EXPECT_EQ(index, -1);

  qid.PopFront();
  EXPECT_EQ(qid.Size(), std::size_t(3));
  qid.PopFront();
  EXPECT_EQ(qid.Size(), std::size_t(2));
  qid.PopFront();
  EXPECT_EQ(qid.Size(), std::size_t(1));
  qid.PopFront();
  EXPECT_EQ(qid.Size(), std::size_t(0));

  EXPECT_QUIC_BUG(qid.PopFront(), "Trying to pop from an empty container.");
}