TEST(HuffmanBuilderTest, ToVector) {
  // Build a small tree.
  HuffmanBuilder builder;
  builder.RecordUsage('a');
  builder.RecordUsage('b');
  builder.RecordUsage('b');
  builder.RecordUsage('c');
  builder.RecordUsage('c');
  builder.RecordUsage('d');
  builder.RecordUsage('d');
  builder.RecordUsage('d');
  builder.RecordUsage('e');
  builder.RecordUsage('e');
  builder.RecordUsage('e');

  std::vector<uint8_t> output = builder.ToVector();

  // This represents 4 nodes (4 groups of 2 uint8_t's) which, when decoded,
  // yields the expected Huffman Tree:
  //                      root (node 3)
  //                     /             \
  //              node 1                 node 2
  //            /       \               /      \
  //         0xE3 (c)    node 0     0xE4 (d)    0xE5 (e)
  //                    /      \
  //                0xE1 (a)    0xE2 (b)
  EXPECT_THAT(output, testing::ElementsAre(0xE1, 0xE2, 0xE3, 0x0, 0xE4, 0xE5,
                                           0x1, 0x2));
}