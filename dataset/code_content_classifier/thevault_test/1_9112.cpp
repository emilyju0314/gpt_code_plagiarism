TEST_F(TrieTest, Remove) {
  FillSmallTree(*trie);

  for (auto i : {2, 3, 4}) {
    EXPECT_OUTCOME_TRUE_1(trie->remove(data[i].first));
  }

  for (auto i : {2, 3, 4}) {
    ASSERT_FALSE(trie->contains(data[i].first));
  }
  ASSERT_TRUE(trie->contains(data[0].first));
  ASSERT_TRUE(trie->contains(data[1].first));
}