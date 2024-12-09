TEST(HuffmanBuilderTest, ToVectorSingle) {
  // Build a single element tree. Another element should be added automatically.
  HuffmanBuilder builder;
  builder.RecordUsage('a');

  std::vector<uint8_t> output = builder.ToVector();

  // This represents 1 node (1 group of 2 uint8_t's) which, when decoded,
  // yields the expected Huffman Tree:
  //                     root (node 0)
  //                     /           \
  //             0x80 (\0)           0xE1 (a)
  //
  // Note: the node \0 node was appended to the tree.
  EXPECT_THAT(output, testing::ElementsAre(0x80, 0xE1));
}