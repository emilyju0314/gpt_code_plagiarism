TEST(StructuredHeaderTest, ParseSH09Item) {
  for (const auto& c : sh09_item_test_cases) {
    SCOPED_TRACE(c.name);
    base::Optional<ListOfLists> result = ParseListOfLists(c.raw);
    if (c.expected.has_value()) {
      EXPECT_TRUE(result.has_value());
      EXPECT_EQ(result->size(), 1UL);
      EXPECT_EQ((*result)[0].size(), 1UL);
      EXPECT_EQ((*result)[0][0], c.expected);
    } else {
      EXPECT_FALSE(result.has_value());
    }
  }
}