TEST_F(TrieTest, ClearPrefix) {
  std::vector<std::pair<Buffer, Buffer>> data = {{"bark"_buf, "123"_buf},
                                                 {"barnacle"_buf, "456"_buf},
                                                 {"bat"_buf, "789"_buf},
                                                 {"batch"_buf, "0-="_buf}};
  for (auto &entry : data) {
    EXPECT_OUTCOME_TRUE_1(trie->put(entry.first, entry.second));
  }
  EXPECT_OUTCOME_TRUE_1(trie->clearPrefix("bar"_buf));
  ASSERT_TRUE(trie->contains("bat"_buf));
  ASSERT_TRUE(trie->contains("batch"_buf));
  ASSERT_FALSE(trie->contains("bark"_buf));
  ASSERT_FALSE(trie->contains("barnacle"_buf));

  EXPECT_OUTCOME_TRUE_1(trie->clearPrefix("batc"_buf));
  ASSERT_TRUE(trie->contains("bat"_buf));
  ASSERT_FALSE(trie->contains("batch"_buf));

  EXPECT_OUTCOME_TRUE_1(trie->clearPrefix("b"_buf));
  ASSERT_FALSE(trie->contains("bat"_buf));
  ASSERT_TRUE(trie->empty());
}