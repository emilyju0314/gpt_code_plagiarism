TEST_F(QuicIntervalDequeTest, PopEmpty) {
  QID qid;
  EXPECT_TRUE(qid.Empty());
  EXPECT_QUIC_BUG(qid.PopFront(), "Trying to pop from an empty container.");
}