TEST_F(TrieTest, Replace) {
  FillSmallTree(*trie);

  EXPECT_OUTCOME_TRUE_1(trie->put(data[1].first, data[3].second));
  EXPECT_OUTCOME_TRUE(res, trie->get(data[1].first));
  ASSERT_EQ(res, data[3].second);
}