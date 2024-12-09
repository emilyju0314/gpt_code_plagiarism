TEST_P(TrieTest, RunCommand) {
  for (auto &command : GetParam()) {
    switch (command.command) {
      case Command::CONTAINS:
        ASSERT_TRUE(trie->contains(command.key));
        break;
      case Command::GET: {
        if (command.value) {
          EXPECT_OUTCOME_TRUE(val, trie->get(command.key));
          ASSERT_EQ(val, command.value.get());
        } else {
          EXPECT_OUTCOME_FALSE(err, trie->get(command.key));
          ASSERT_EQ(
              err.value(),
              static_cast<int>(sgns::storage::trie::TrieError::NO_VALUE));
        }
        break;
      }
      case Command::PUT: {
        EXPECT_OUTCOME_TRUE_1(trie->put(command.key, command.value.get()));
        break;
      }
      case Command::REMOVE: {
        EXPECT_OUTCOME_TRUE_1(trie->remove(command.key));
        break;
      }
    }
  }
}