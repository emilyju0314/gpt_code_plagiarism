TEST_F(SuperGeniusTrieCursorTest, Lexicographical) {
  std::vector<std::pair<Buffer, Buffer>> vals{
      {"0102"_hex2buf, "0102"_hex2buf},
      {"0103"_hex2buf, "0103"_hex2buf},
      {"010304"_hex2buf, "010304"_hex2buf},
      {"05"_hex2buf, "05"_hex2buf},
      {"06"_hex2buf, "06"_hex2buf},
      {"0607"_hex2buf, "0607"_hex2buf},
      {"060708"_hex2buf, "060708"_hex2buf},
      {"06070801"_hex2buf, "06070801"_hex2buf},
      {"06070802"_hex2buf, "06070802"_hex2buf},
      {"06070803"_hex2buf, "06070803"_hex2buf}};
  auto trie = makeTrie(vals);
  auto c = trie->cursor();
  EXPECT_OUTCOME_FALSE_1(c->seek("f"_buf));
  EXPECT_OUTCOME_TRUE_1(c->seek("06"_hex2buf));
  Buffer prev_key{0};
  do {
    EXPECT_OUTCOME_TRUE(key, c->key());
    ASSERT_LT(prev_key, key);
    prev_key = key;
    EXPECT_OUTCOME_TRUE_1(c->next());
  } while (c->isValid());
}