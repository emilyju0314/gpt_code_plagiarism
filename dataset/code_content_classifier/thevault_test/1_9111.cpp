TEST_F(TrieTest, Put) {
  FillSmallTree(*trie);

  for (auto &entry : data) {
    EXPECT_OUTCOME_TRUE(res, trie->get(entry.first));
    ASSERT_EQ(res, entry.second);
  }
  EXPECT_OUTCOME_TRUE_1(trie->put("102030"_hex2buf, "0a0b0c"_hex2buf));
  EXPECT_OUTCOME_TRUE_1(trie->put("104050"_hex2buf, "0a0b0c"_hex2buf));
  EXPECT_OUTCOME_TRUE_1(trie->put("102030"_hex2buf, "010203"_hex2buf));
  EXPECT_OUTCOME_TRUE(v1, trie->get("102030"_hex2buf));
  ASSERT_EQ(v1, "010203"_hex2buf);
  EXPECT_OUTCOME_TRUE(v2, trie->get("104050"_hex2buf));
  ASSERT_EQ(v2, "0a0b0c"_hex2buf);
  EXPECT_OUTCOME_TRUE_1(trie->put("1332"_hex2buf, ""_buf));
  EXPECT_OUTCOME_TRUE(v3, trie->get("1332"_hex2buf));
  ASSERT_EQ(v3, ""_buf);
}