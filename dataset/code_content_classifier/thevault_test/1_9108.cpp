TEST_F(SuperGeniusTrieCursorTest, BigPseudoRandomTrieRandomStart) {
  auto &&[trie, keys] = generateRandomTrie(100, 8, 32);
  const auto cursor = trie->cursor();
  EXPECT_OUTCOME_TRUE_1(cursor->next());
  size_t keys_behind =
      0;  // number of keys lexicographically lesser than current
  for (auto start_key : keys) {
    EXPECT_OUTCOME_TRUE_1(cursor->seek(start_key));
    auto keys_copy = std::set<Buffer>(keys);
    while (cursor->isValid()) {
      EXPECT_OUTCOME_TRUE(key, cursor->key());
      EXPECT_OUTCOME_TRUE(value, cursor->value());
      ASSERT_EQ(key, value);
      ASSERT_TRUE(keys_copy.find(key) != keys_copy.end());
      keys_copy.erase(key);
      EXPECT_OUTCOME_TRUE_1(cursor->next());
    }
    ASSERT_EQ(keys_copy.size(),
              keys_behind++);  // unvisited keys are those already visited when
                               // starting from lesser keys
  }
}