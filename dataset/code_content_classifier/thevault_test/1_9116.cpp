TEST_F(TrieTest, GetPath) {
  // TODO(Harrm) PRE-461 Make parametrized
  const std::vector<std::pair<Buffer, Buffer>> data = {
      {"123456"_hex2buf, "42"_hex2buf},
      {"1234"_hex2buf, "1234"_hex2buf},
      {"010203"_hex2buf, "0a0b"_hex2buf},
      {"010a0b"_hex2buf, "1337"_hex2buf},
      {"0a0b0c"_hex2buf, "deadbeef"_hex2buf}};

  for (auto &entry : TrieTest::data) {
    EXPECT_OUTCOME_TRUE_1(trie->put(entry.first, entry.second));
  }

  EXPECT_OUTCOME_TRUE(
      path, trie->getPath(trie->getRoot(), KeyNibbles{"010203040506"_hex2buf}));
  auto root = trie->getRoot();
  auto node1 = trie->getNode(root, KeyNibbles{1, 2, 3, 4}).value();
  auto it = path.begin();
  ASSERT_EQ(it->first, root);
  ASSERT_EQ(it->first->children[it->second], node1);
  ASSERT_EQ((++it)->first, node1);
}