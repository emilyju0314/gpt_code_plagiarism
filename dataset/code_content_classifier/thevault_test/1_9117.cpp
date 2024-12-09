TEST_F(TrieTest, GetPathToInvalid) {
  const std::vector<std::pair<Buffer, Buffer>> data = {
      {"123456"_hex2buf, "42"_hex2buf},
      {"1234"_hex2buf, "1234"_hex2buf},
      {"010203"_hex2buf, "0a0b"_hex2buf},
      {"010a0b"_hex2buf, "1337"_hex2buf},
      {"0a0b0c"_hex2buf, "deadbeef"_hex2buf}};

  for (auto &entry : TrieTest::data) {
    EXPECT_OUTCOME_TRUE_1(trie->put(entry.first, entry.second));
  }

  EXPECT_OUTCOME_FALSE(
      path, trie->getPath(trie->getRoot(), KeyNibbles{"0a0b0c0d0e0f"_hex2buf}));
}