TEST(ChangesTrieTest, IntegrationWithOverlay) {
  using SessionPtr = std::shared_ptr<sgns::api::Session>;
  using SubscriptionEngineType =
      SubscriptionEngine<Buffer, SessionPtr, Buffer, BlockHash>;

  // GIVEN
  auto factory = std::make_shared<SuperGeniusTrieFactoryImpl>();
  auto codec = std::make_shared<SuperGeniusCodec>();
  auto backend = std::make_shared<TrieStorageBackendImpl>(
      std::make_shared<InMemoryStorage>(), Buffer{});
  auto serializer =
      std::make_shared<TrieSerializerImpl>(factory, codec, backend);
  auto subscription_engine = std::make_shared<SubscriptionEngineType>();
  std::shared_ptr<ChangesTracker> changes_tracker =
      std::make_shared<StorageChangesTrackerImpl>(
          factory, codec, subscription_engine);
  EXPECT_OUTCOME_TRUE_1(changes_tracker->onBlockChange("aaa"_hash256, 42));
  auto batch = std::make_shared<PersistentTrieBatchImpl>(
      codec,
      serializer,
      boost::make_optional(changes_tracker),
      factory->createEmpty(
          [](auto branch, auto idx) { return branch->children.at(idx); }),
      [](auto &buf) {});

  EXPECT_OUTCOME_TRUE_1(
      batch->put(":extrinsic_index"_buf, Buffer{scale::encode(42).value()}));
  EXPECT_OUTCOME_TRUE_1(batch->put("abc"_buf, "123"_buf));
  EXPECT_OUTCOME_TRUE_1(batch->put("cde"_buf, "345"_buf));

  auto repo = std::make_shared<BlockHeaderRepositoryMock>();
  EXPECT_CALL(*repo, getNumberByHash(_)).WillRepeatedly(Return(42));

  EXPECT_OUTCOME_TRUE_1(
      changes_tracker->constructChangesTrie("aaa"_hash256, {}));
  // THEN SUCCESS
}