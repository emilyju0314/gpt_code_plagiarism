TEST(OrderedTrieHash, DoesntFail) {
  std::vector vals{"aarakocra"_buf, "byzantine"_buf, "crest"_buf};
  EXPECT_OUTCOME_TRUE_1(
      sgns::storage::trie::calculateOrderedTrieHash(vals.begin(), vals.end()))
}