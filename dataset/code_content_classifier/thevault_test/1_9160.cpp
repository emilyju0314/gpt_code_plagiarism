TEST_F(TrieBatchTest, Put) {
  auto batch = trie->getPersistentBatch().value();
  FillSmallTrieWithBatch(*batch);
  // changes are not yet commited
  auto new_batch = trie->getEphemeralBatch().value();
  for (auto &entry : data) {
    EXPECT_OUTCOME_FALSE(err, new_batch->get(entry.first));
    ASSERT_EQ(err.value(),
              static_cast<int>(sgns::storage::trie::TrieError::NO_VALUE));
  }
  EXPECT_OUTCOME_TRUE_void(r, batch->commit());
  // changes are commited
  new_batch = trie->getEphemeralBatch().value();
  for (auto &entry : data) {
    EXPECT_OUTCOME_TRUE(res, new_batch->get(entry.first));
    ASSERT_EQ(res, entry.second);
  }

  EXPECT_OUTCOME_TRUE_1(new_batch->put("102030"_hex2buf, "010203"_hex2buf));
  EXPECT_OUTCOME_TRUE_1(new_batch->put("104050"_hex2buf, "0a0b0c"_hex2buf));
  EXPECT_OUTCOME_TRUE(v1, new_batch->get("102030"_hex2buf));
  ASSERT_EQ(v1, "010203"_hex2buf);
  EXPECT_OUTCOME_TRUE(v2, new_batch->get("104050"_hex2buf));
  ASSERT_EQ(v2, "0a0b0c"_hex2buf);
}