TEST(BlockChain, Reset) {
  BlockChain<int, 1024> chain;
  chain.push_back_n(5, 1024 * 3);
  EXPECT_GT(chain.size(), 0);
  const Block<int, 1024>* blockPtr[] = {chain.root(), nullptr, nullptr};
  blockPtr[1] = blockPtr[0]->next();
  blockPtr[2] = blockPtr[1]->next();

  // Tests below rely quite a lot on the internals of BlockChain, but this
  // seems the easiest way to actually test re-usage of the block pointers
  chain.Reset();
  EXPECT_EQ(chain.size(), 0);
  EXPECT_EQ(blockPtr[0]->size(), 0);
  EXPECT_EQ(blockPtr[1]->size(), 0);
  EXPECT_EQ(blockPtr[2]->size(), 0);

  chain.push_back_n(10, 1024);
  EXPECT_GT(chain.size(), 0);
  EXPECT_EQ(chain.root()->data()[0], 10);
  EXPECT_EQ(chain.root(), blockPtr[0]);
  EXPECT_EQ(chain.root()->next(), blockPtr[1]);
  EXPECT_EQ(blockPtr[1]->size(), 0);

  chain.push_back_n(10, 1024);
  EXPECT_EQ(chain.root()->next(), blockPtr[1]);
  EXPECT_EQ(blockPtr[1]->size(), 1024);
  EXPECT_EQ(blockPtr[2]->size(), 0);

  chain.push_back_n(10, 1024);
  EXPECT_EQ(chain.root()->next()->next(), blockPtr[2]);
  EXPECT_EQ(blockPtr[2]->size(), 1024);
}