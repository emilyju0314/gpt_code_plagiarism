TEST_F(QuicIntervalDequeTest, ZeroSizedInterval) {
  QID qid;
  EXPECT_QUIC_BUG(qid.PushBack(TestIntervalItem(0, 0, 0)),
                  "Trying to save empty interval to .");
}