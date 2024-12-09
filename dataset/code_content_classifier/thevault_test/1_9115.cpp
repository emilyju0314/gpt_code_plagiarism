TEST_F(TrieTest, EmptyTrie) {
  ASSERT_TRUE(trie->empty());
  EXPECT_OUTCOME_TRUE_1(trie->put({0}, "asdasd"_buf));
  ASSERT_FALSE(trie->empty());
}