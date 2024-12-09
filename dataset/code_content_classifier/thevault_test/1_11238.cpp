TEST_F(PostgresBlockStorageTest, ForEach) {
  auto tx = TestTransactionBuilder().creatorAccountId(creator_).build();
  std::vector<shared_model::proto::Transaction> txs;
  txs.push_back(std::move(tx));
  auto block = TestBlockBuilder().height(height_).transactions(txs).build();
  auto another_block =
      TestBlockBuilder().height(height_ + 1).transactions(txs).build();

  ASSERT_TRUE(block_storage_->insert(clone(block)));
  ASSERT_TRUE(block_storage_->insert(clone(another_block)));

  size_t count = 0;

  block_storage_->forEach([&count, &block, &another_block](const auto &b) {
    ++count;
    if (b->height() == block.height()) {
      ASSERT_EQ(b->blob(), block.blob());
    } else if (b->height() == another_block.height()) {
      ASSERT_EQ(b->blob(), another_block.blob());
    } else {
      FAIL() << "Unexpected block height returned: " << b->height();
    }
  });

  ASSERT_EQ(2, count);
}