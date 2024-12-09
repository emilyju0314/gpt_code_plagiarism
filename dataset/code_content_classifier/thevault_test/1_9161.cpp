TEST_F(TrieBatchTest, ConsistentOnFailure) {
  auto db = std::make_unique<MockDb>();
  /**
   * Five times the storage will function correctly, after which it will yield
   * an error
   */
  auto &&expectation = EXPECT_CALL(*db, put(_, _))
                           .Times(5)
                           .WillRepeatedly(Invoke(db.get(), &MockDb::true_put));

  EXPECT_CALL(*db, put(_, _))
      .After(expectation)
      .WillOnce(Return(SuperGeniusCodec::Error::UNKNOWN_NODE_TYPE));

  auto factory = std::make_shared<SuperGeniusTrieFactoryImpl>();
  auto codec = std::make_shared<SuperGeniusCodec>();
  auto serializer = std::make_shared<TrieSerializerImpl>(
      factory,
      codec,
      std::make_shared<TrieStorageBackendImpl>(std::move(db), kNodePrefix));
  auto trie =
      TrieStorageImpl::createEmpty(factory, codec, serializer, boost::none)
           .value();
  auto batch = trie->getPersistentBatch().value();

  EXPECT_OUTCOME_TRUE_1(batch->put("123"_buf, "111"_buf));
  EXPECT_OUTCOME_TRUE_1(batch->commit());

  auto old_root = trie->getRootHash();
  ASSERT_FALSE(old_root.empty());
  EXPECT_OUTCOME_TRUE_1(batch->put("133"_buf, "111"_buf));
  EXPECT_OUTCOME_TRUE_1(batch->put("124"_buf, "111"_buf));
  EXPECT_OUTCOME_TRUE_1(batch->put("154"_buf, "111"_buf));
  ASSERT_FALSE(batch->commit());

  // if the root hash is unchanged, then the trie content is kept untouched
  // (which we want, as the batch commit failed)
  ASSERT_EQ(trie->getRootHash(), old_root);
}