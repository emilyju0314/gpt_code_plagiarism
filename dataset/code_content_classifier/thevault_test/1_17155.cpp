TEST_F(QuicIntervalDequeTest, IteratorEmpty) {
  QID qid;
  auto it = qid.DataAt(0);
  EXPECT_EQ(it, qid.DataEnd());
}